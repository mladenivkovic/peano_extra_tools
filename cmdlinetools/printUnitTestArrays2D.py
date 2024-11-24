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


#  file = "test_sml_2D.hdf5"
file = "test_sml_multiscale_2D.hdf5"
h_tolerance = 1.0e-6
kernel = "quartic_spline_vectorized"
ndim = 2

# target number of neighbours
nneigh = [8, 15, 20]


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

boxsize = f["Header"].attrs["BoxSize"]
random_seed = f["Header"].attrs["RandomSeed"]
max_displacement = f["Header"].attrs["MaxDisplacement"]
numpy_version = f["Header"].attrs["NumpyVersion"]
f.close()


# Sort by particle ID
sort_ic = np.argsort(ids)
ids = ids[sort_ic]
coords = coords[sort_ic]
sml_ic = sml_ic[sort_ic]

# select inner and outer box in the middle of the actual box
# then arange them such that the inner box is in the middle
# of the array.
# This is so that I don't have to modify the unit tests.


dx_inner = 0.15
dx_outer = 0.3


inner_mask = coords[:, 0] > (0.5 * boxsize - dx_inner)
inner_mask = np.logical_and(inner_mask, coords[:, 0] < (0.5 * boxsize + dx_inner))
inner_mask = np.logical_and(inner_mask, coords[:, 1] > (0.5 * boxsize - dx_inner))
inner_mask = np.logical_and(inner_mask, coords[:, 1] < (0.5 * boxsize + dx_inner))

outer_mask = coords[:, 0] > 0.5 * boxsize - dx_outer
outer_mask = np.logical_and(outer_mask, coords[:, 0] < 0.5 * boxsize + dx_outer)
outer_mask = np.logical_and(outer_mask, coords[:, 1] > 0.5 * boxsize - dx_outer)
outer_mask = np.logical_and(outer_mask, coords[:, 1] < 0.5 * boxsize + dx_outer)


outer_mask = np.logical_and(outer_mask, np.logical_not(inner_mask))

mask_full = np.logical_or(inner_mask, outer_mask)

#  from matplotlib import  pyplot as plt
#  plt.figure()
#  plt.subplot(121)
#  plt.scatter(coords[inner_mask, 0], coords[inner_mask, 1], c='b')
#  plt.subplot(122)
#  plt.scatter(coords[outer_mask, 0], coords[outer_mask, 1], c='r')
#  plt.show()
#  quit()


count_inner = np.count_nonzero(inner_mask)
count_outer = np.count_nonzero(outer_mask)

print("Inner:", count_inner)
print("Outer:", count_outer)

size = count_inner + count_outer


# Filter out unwanted particles
# Sort the outer particles first, and the inner particles last
ids_copy = ids.copy()
ids = np.zeros(size, dtype=int)
ids[:count_outer] = ids_copy[outer_mask]
ids[count_outer:] = ids_copy[inner_mask]

coords_copy = coords.copy()
coords = np.zeros((size, 3))
coords[:count_outer, :] = coords_copy[outer_mask, :]
coords[count_outer:, :] = coords_copy[inner_mask, :]

sml_ic_copy = sml_ic.copy()
sml_ic = np.zeros(size)
sml_ic[:count_outer] = sml_ic_copy[outer_mask]
sml_ic[count_outer:] = sml_ic_copy[inner_mask]


# Now that we've filtered out unwanted particles, refresh the masks
# to fit into the new array sizes
inner_mask = coords[:, 0] > 0.5 * boxsize - dx_inner
inner_mask = np.logical_and(inner_mask, coords[:, 0] < 0.5 * boxsize + dx_inner)
inner_mask = np.logical_and(inner_mask, coords[:, 1] > 0.5 * boxsize - dx_inner)
inner_mask = np.logical_and(inner_mask, coords[:, 1] < 0.5 * boxsize + dx_inner)

outer_mask = coords[:, 0] > 0.5 * boxsize - dx_outer
outer_mask = np.logical_and(outer_mask, coords[:, 0] < 0.5 * boxsize + dx_outer)
outer_mask = np.logical_and(outer_mask, coords[:, 1] > 0.5 * boxsize - dx_outer)
outer_mask = np.logical_and(outer_mask, coords[:, 1] < 0.5 * boxsize + dx_outer)

outer_mask = np.logical_and(outer_mask, np.logical_not(inner_mask))


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
    distances, indexes = tree.query(coords, k=n + 20 * ndim)
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
    out.write(indent + f"// Size of inner square: {dx_inner}\n")
    out.write(indent + f"// Size of outer square: {dx_outer}\n\n")

    out.write(indent + f"IC.sampleSize = {size};\n\n")

    out.write(indent + f"IC.indexBegin = {count_outer};\n")
    out.write(indent + f"IC.indexEnd = {size};\n\n")

    out.write(indent + f"IC.h_tolerance = {h_tolerance};\n")
    out.write(indent + f"IC.resolution_eta = {eta};\n\n")

    out.write(indent + f"IC.h_min = {sml_python.min()};\n")
    out.write(indent + f"IC.h_max = {sml_python.max()};\n\n")

    out.write(indent + f"IC.coords = {{\n")

    for mask, count, is_last in [
        (inner_mask, count_inner, False),
        (outer_mask, count_outer, True),
    ]:
        for i in range(count):
            if i == count - 1 and is_last:
                comma = "\n"
            else:
                comma = ",\n"

            c = coords[mask][i]
            if c.shape[0] == 1:
                out.write(indent + f"  {{ {c[0]:14.8e}, 0., 0. }}" + comma)
            elif c.shape[0] == 2:
                out.write(indent + f"  {{ {c[0]:14.8e}, {c[1]:14.8e}, 0. }}" + comma)
            elif c.shape[0] == 3:
                out.write(
                    indent + f"  {{ {c[0]:14.8e}, {c[1]:14.8e}, {c[2]:14.8e} }}" + comma
                )

    out.write(indent + "};\n\n")

    # safety check
    ids_full = np.zeros(count_outer + count_inner, int)
    ind = 0

    out.write(indent + f"IC.ids = {{\n")
    for mask, count, is_last in [
        (inner_mask, count_inner, False),
        (outer_mask, count_outer, True),
    ]:
        for i in range(count):
            if i == count - 1 and is_last:
                comma = "\n"
            else:
                comma = ",\n"

            c = ids[mask][i]
            ids_full[ind] = c
            ind += 1
            out.write(indent + f"  {c}" + comma)

    out.write(indent + "};\n\n")

    uniques = np.unique(ids_full)
    if uniques.shape != ids_full.shape:
        raise ValueError("Have non-unique particle IDs")

    out.write(indent + f"IC.sml_init = {{\n")
    for mask, count, is_last in [
        (inner_mask, count_inner, False),
        (outer_mask, count_outer, True),
    ]:
        for i in range(count):
            if i == count - 1 and is_last:
                comma = "\n"
            else:
                comma = ",\n"

            s = sml_ic[mask][i]
            out.write(indent + f"  {s}" + comma)

    out.write(indent + "};\n\n")

    out.write(indent + f"IC.sml_solution = {{")
    for mask, count, is_last in [
        (inner_mask, count_inner, False),
        (outer_mask, count_outer, True),
    ]:
        for i in range(count):
            if i == count - 1 and is_last:
                comma = "\n"
            else:
                comma = ",\n"

            s = sml_python[mask][i]
            out.write(indent + f"  {s}" + comma)

    out.write(indent + "};\n\n")

    out.write(indent + "return IC;\n")

    out.close()
    print("Written to", outname)
