#!/usr/bin/env python3


# ------------------------------------------------------------
# Extract and print data for smoothinglength unit test
#
# Intended to be run in Peano/tests/swift2/test-smoothing-length-computation/test-smoothing-length-computation-1D
# Just comment/uncomment file you want to run, kernel to use, etc etc
# ------------------------------------------------------------


import h5py
from scipy.spatial import KDTree
import numpy as np
import sys
import os
import peano4
from peano4.toolbox.particles.postprocessing.ParticleVTUReader import ParticleVTUReader
import swift2.sphtools
import multiprocessing


#  file = "test_sml_1D.hdf5"
file = "test_sml_multiscale_1D.hdf5"
h_tolerance = 1.0e-12
kernel = "quartic_spline_vectorized"
ndim = 1

# target number of neighbours
nneigh = [3, 5, 10]


# start and end of indexes of particle array to take
x_start = 0.75
x_end = 0.9


print(" --- IC file:                    ", file)
print(" --- Dimensions:                 ", ndim)
print(" --- SPH Kernel:                 ", kernel)
print(" --- h tolerance:                ", h_tolerance)


# Read Data
# -------------------------

f = h5py.File(file)

gas = f["PartType0"]
coords = gas["Coordinates"][:]
ids = gas["ParticleIDs"][:]
sml_ic = gas["SmoothingLength"][:]
random_seed = f["Header"].attrs["RandomSeed"]
max_displacement = f["Header"].attrs["MaxDisplacement"]
numpy_version = f["Header"].attrs["NumpyVersion"]
f.close()


mask = coords[:, 0] > x_start
mask = np.logical_and(mask, coords[:, 0] < x_end)

ids = ids[mask]
coords = coords[mask]
sml_ic = sml_ic[mask]


# Sort by particle position
sort_ic = np.argsort(coords[:, 0])

ids = ids[sort_ic]
coords = coords[sort_ic]
sml_ic = sml_ic[sort_ic]


# Main loop
for n in nneigh:
    eta = swift2.sphtools.eta_from_number_of_neighbours(n, kernel=kernel, ndim=ndim)

    print(" --- Starting run for:")
    print("     Target number of neighbours:", n)
    print("     Target eta:                 ", eta)

    outname = f"solution_n={n}-" + file.strip(".hdf5") + ".dat"

    out = open(outname, "w")

    # Get expected results
    # -------------------------

    tree = KDTree(coords)
    distances, indexes = tree.query(coords, k=2 * n + 10 * ndim)
    neighbours = coords[indexes]

    npart = coords.shape[0]
    sml_python = np.zeros((npart))

    def sml_search(i):
        # the KDTree returns the particle itself as a neighbour too.
        # it is stored at the first index, with distance 0.
        xp = neighbours[i, 0, :]
        xn = neighbours[i, 1:, :]

        verb = False
        h = swift2.sphtools.find_smoothing_length(
            xp,
            xn,
            kernel=kernel,
            eta=eta,
            h_tolerance=h_tolerance,
            ndim=ndim,
            verbose=verb,
        )
        return h

    pool = multiprocessing.Pool()
    sml_python[:] = pool.map(sml_search, (i for i in range(npart)))

    indent = "  "
    size = ids.shape[0]

    out.write("\n")
    out.write(indent + "struct InitialConditions IC;\n\n")
    out.write(indent + f'IC.name = "{outname}";\n\n')

    filepath = os.path.join(os.getcwd(), file)
    if filepath.startswith("/home/mivkov/Durham/"):
        filepath = filepath[len("/home/mivkov/Durham/") :]
    out.write(indent + f"// File: {filepath}\n")
    out.write(indent + f"// Random Seed: {random_seed}\n")
    out.write(indent + f"// Kernel: {kernel}\n")
    out.write(indent + f"// Numpy version: {numpy_version}\n")
    out.write(indent + f"// Max displacement: {max_displacement}\n")
    out.write(indent + f"// IC particle position start: {x_start}\n")
    out.write(indent + f"// IC particle position end: {x_end}\n\n")

    out.write(indent + f"IC.sampleSize = {size};\n\n")

    out.write(indent + f"IC.indexBegin = 10;\n")
    out.write(indent + f"IC.indexEnd = {size-10};\n\n")

    out.write(indent + f"IC.h_tolerance = {h_tolerance};\n")
    out.write(indent + f"IC.resolution_eta = {eta};\n\n")

    out.write(indent + f"IC.h_min = {sml_python.min()};\n")
    out.write(indent + f"IC.h_max = {sml_python.max()};\n\n")

    out.write(indent + f"IC.coords = {{\n")

    for i in range(coords.shape[0]):
        if i != size - 1:
            comma = ",\n"
        else:
            comma = "\n"

        c = coords[i]
        if c.shape[0] == 1:
            out.write(indent + f"  {{ {c[0]:14.8e}, 0., 0. }}" + comma)
        elif c.shape[0] == 2:
            out.write(indent + f"  {{ {c[0]:14.8e}, {c[1]:14.8e}, 0. }}" + comma)
        elif c.shape[0] == 3:
            out.write(
                indent + f"  {{ {c[0]:14.8e}, {c[1]:14.8e}, {c[2]:14.8e} }}" + comma
            )

    out.write(indent + "};\n\n")

    out.write(indent + f"IC.ids = {{\n")
    for i in range(coords.shape[0]):
        if i != size - 1:
            comma = ",\n"
        else:
            comma = "\n"
        c = ids[i]
        out.write(indent + f"  {c}" + comma)

    out.write(indent + "};\n\n")

    out.write(indent + f"IC.sml_init = {{\n")
    for i in range(coords.shape[0]):
        if i != size - 1:
            comma = ",\n"
        else:
            comma = "\n"
        s = sml_ic[i]
        out.write(indent + f"  {s}" + comma)

    out.write(indent + "};\n\n")

    out.write(indent + f"IC.sml_solution = {{\n")
    for i in range(coords.shape[0]):
        if i != size - 1:
            comma = ",\n"
        else:
            comma = "\n"
        s = sml_python[i]
        out.write(indent + f"  {s}" + comma)

    out.write(indent + "};\n\n")

    out.write(indent + "return IC;\n")

    out.close()
    print("Written to", outname)
