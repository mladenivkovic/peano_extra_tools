#!/usr/bin/env python3

# Read in neighbour counts, recompute them with python.

from peano4.toolbox.particles.postprocessing.ParticleVTUReader import ParticleVTUReader
import swift2.sphtools as sphtools
import numpy as np
import os
from scipy.spatial import KDTree
import argparse


parser = argparse.ArgumentParser(description="Check Neighbour Counts")
parser.add_argument(
    "-v",
    "--verbose",
    dest="verbose",
    action="store_true",
    default=False,
    help="Verbose",
)
parser.add_argument(
    "-k",
    "--kernel",
    dest="kernel",
    type=str,
    default="quartic_spline",
    choices=sphtools.sph_kernel_list,
    help="SPH kernel function to use.",
)
parser.add_argument(
    "-d",
    "--dimensions",
    dest="dimensions",
    type=int,
    default="1",
    choices=[1,2,3],
    help="how many dimensions to use",
)
parser.add_argument(
    "filename",
    type=str,
)
args = parser.parse_args()




vtufile = args.filename
if not os.path.exists(vtufile):
    raise FileNotFoundError("no file {}".format(vtufile))

kernel = args.kernel
ndim = args.dimensions

kernel_gamma = sphtools.sph_kernel_get_H(1.0, kernel, ndim)

#----------------------------------------
# Read in data
#----------------------------------------
reader = ParticleVTUReader(vtufile=vtufile, verbose=False)
partData = reader.load()

coords = partData.x
searchRadius = partData.search_radius
smoothingLength = partData.smoothingLength

ids = partData.partid
ids = ids.astype(int)

Ncount_D = partData.densityNeighbourCount
Ncount_D = Ncount_D.astype(int)
Ncount_F = partData.forceNeighbourCount
Ncount_F = Ncount_F.astype(int)

# sort particles by index
sortind = np.argsort(ids)
coords = coords[sortind]
searchRadius = searchRadius[sortind]
smoothingLength = smoothingLength[sortind]
ids = ids[sortind]
Ncount_D = Ncount_D[sortind]
Ncount_F = Ncount_F[sortind]

maxn =max(Ncount_D.max(), Ncount_F.max())


# Check that search radius is >= compact support radius
H_py = smoothingLength * kernel_gamma
fishy = H_py > searchRadius

if fishy.any():
    errcount = np.count_nonzero(fishy)
    print("Found", errcount, "particles with search radius < compact support")



# Check density counts <= Force counts

fishy = Ncount_D > Ncount_F
if fishy.any():
    errcount = np.count_nonzero(fishy)
    print("Found", errcount, "particles with density interactions > force interactions")


# Search for neighbours
tree = KDTree(coords)
distances, indexes = tree.query(coords, k=2*maxn+10)
neighbour_coords = coords[indexes]

nparts = Ncount_F.shape[0]
NNeigh_density_py = np.zeros(nparts, dtype=int)
NNeigh_force_py = np.zeros(nparts, dtype=int)


for p in range(nparts):

    xp = neighbour_coords[p, 0, :]
    xn = neighbour_coords[p, 1:, :]
    r = distances[p, 1:]
    ninds = indexes[p,1:]

    Hp = smoothingLength[p] * kernel_gamma

    for n in range(r.shape[0]):
        dens_neigh = r[n] <= Hp
        if (dens_neigh):
            NNeigh_density_py[p] += 1

        Hn = smoothingLength[ninds[n]] * kernel_gamma
        force_neigh = r[n] <= Hn
        if dens_neigh or force_neigh:
            NNeigh_force_py[p] += 1


# ==============================
# Actual Checks
# ==============================


fishy = Ncount_D > Ncount_F
if fishy.any():
    errcount = np.count_nonzero(fishy)
    print("In Peano: Found", errcount, "particles with density interactions > force interactions")
else:
    print("Passed density <= force")



fishy = NNeigh_density_py > NNeigh_force_py
if fishy.any():
    errcount = np.count_nonzero(fishy)
    print("In python reproduction: Found", errcount, "particles with density interactions > force interactions")
else:
    print("Passed density py <= force py")

fishy = NNeigh_density_py != Ncount_D
if fishy.any():
    errcount = np.count_nonzero(fishy)
    print("In python reproduction: Found", errcount, "particles with different neighbour counts in DENSITY")

    for i in range(smoothingLength.shape[0]):
        if fishy[i]:

            dist = distances[i][1:]
            sml = smoothingLength[i]
            neighbours = indexes[i, 1:]

            H = sml * kernel_gamma

            print(f"Peano count: {Ncount_D[i]}")
            print(f"Py count:    {NNeigh_density_py[i]}")
            print(f"Diff:        {NNeigh_density_py[i] - Ncount_D[i]}")
            print(f"ID:          {ids[i]}")

            for n, nind in enumerate(neighbours):

                rnew = np.sqrt(np.sum((coords[nind] - coords[i])**2))
                r = dist[n]
                if r/H  < 1.01 :
                    print(f"    Neighbour ID:  {ids[nind]}    r/H:   {r / H}  coords: {coords[nind]} {r} {H} {kernel_gamma} {sml}")


    print((NNeigh_density_py - Ncount_D)[fishy])
    print("IDs:")
    print(ids[fishy])
else:
    print("Passed density py == density peano")




fishy = NNeigh_force_py != Ncount_F
if fishy.any():
    errcount = np.count_nonzero(fishy)
    print("In python reproduction: Found", errcount, "particles with different neighbour counts in FORCE")

    for i in range(smoothingLength.shape[0]):
        if fishy[i]:

            dist = distances[i][1:]
            neighbours = indexes[i, 1:]
            sml = smoothingLength[i]
            Hi = sml * kernel_gamma


            print(f"Peano count: {Ncount_F[i]}")
            print(f"Py count:    {NNeigh_force_py[i]}")
            print(f"Diff:        {NNeigh_force_py[i] - Ncount_F[i]}")
            print(f"ID:          {ids[i]}")

            for n, nind in enumerate(neighbours):

                sml_n = smoothingLength[nind]
                Hn = sml_n * kernel_gamma
                rnew = np.sqrt(np.sum((coords[nind] - coords[i])**2))
                r = dist[n]
                cutoff = 2.
                if r/Hi <= cutoff or r/Hn <= cutoff:
                    print(f"    Neighbour ID:  {ids[nind]}    r/Hi:   {r / Hi:12.6f}  r/H_n: {r / Hn:12.6f} coords: {coords[nind]} r:{r} Hi:{Hi} Hn:{Hn}")


    print((NNeigh_density_py - Ncount_D)[fishy])
    print("IDs:")
    print(ids[fishy])
else:
    print("Passed force py == force peano")


