#!/usr/bin/env python3


# -------------------------------------------
# Extract and print data for unit test
# -------------------------------------------


import h5py
from scipy.spatial import KDTree
import numpy as np
import sys
import peano4
from peano4.toolbox.particles.postprocessing.ParticleVTUReader import ParticleVTUReader
import swift2.sphtools



file = "test_sml_2D.hdf5"
h_tolerance = 1.e-6
kernel = "quartic_spline"
ndim = 2

eta = 1.2761313865909358
nneigh = swift2.sphtools.number_of_neighbours_from_eta(
    eta, kernel=kernel, ndim=ndim
    )



print(" --- IC file:                    ", file)
print(" --- Dimensions:                 ", ndim)
print(" --- SPH Kernel:                 ", kernel)
print(" --- Target number of neighbours:", nneigh)
print(" --- Target eta:                 ", eta)
print(" --- h tolerance:                ", h_tolerance)


# Read Data
# -------------------------

f = h5py.File(file)

gas = f["PartType0"]
coords = gas["Coordinates"][:]
ids = gas["ParticleIDs"][:]
sml_ic = gas["SmoothingLength"][:]

boxsize = f["Header"].attrs["BoxSize"]

f.close()


# Sort by particle ID
sort_ic = np.argsort(ids)
ids = ids[sort_ic]
coords = coords[sort_ic]


# Get expected results
# -------------------------

tree = KDTree(coords)
distances, indexes = tree.query(coords, k=nneigh + 10 * ndim)
neighbours = coords[indexes]

npart = coords.shape[0]
sml_python = np.zeros((npart))

for i in range(npart):
    # the KDTree returns the particle itself as a neighbour too.
    # it is stored at the first index, with distance 0.
    xp = neighbours[i, 0, :]
    xn = neighbours[i, 1:, :]
    h = swift2.sphtools.find_smoothing_length(
        xp, xn, kernel=kernel, eta=eta, h_tolerance=h_tolerance, ndim=ndim
    )
    sml_python[i] = h




# select inner and outer box in the middle of the actual box
# then arange them such that the inner box is in the middle
# of the array.
# This is so that I don't have to modify the unit tests.


dx_inner = 0.15
dx_outer = 0.4



inner_mask = coords[:, 0] > 0.5 * boxsize - dx_inner
inner_mask = np.logical_and(inner_mask, coords[:, 0] < 0.5 * boxsize + dx_inner)
inner_mask = np.logical_and(inner_mask, coords[:, 1] > 0.5 * boxsize - dx_inner)
inner_mask = np.logical_and(inner_mask, coords[:, 1] < 0.5 * boxsize + dx_inner)

outer_mask = coords[:, 0] > 0.5 * boxsize - dx_outer
outer_mask = np.logical_and(outer_mask, coords[:, 0] < 0.5 * boxsize + dx_outer)
outer_mask = np.logical_and(outer_mask, coords[:, 1] > 0.5 * boxsize - dx_outer)
outer_mask = np.logical_and(outer_mask, coords[:, 1] < 0.5 * boxsize + dx_outer)


outer_mask = np.logical_and(outer_mask, np.logical_not(inner_mask))



#  from matplotlib import  pyplot as plt
#  plt.figure()
#  plt.subplot(121)
#  plt.scatter(coords[inner_mask, 0], coords[inner_mask, 1])
#  plt.subplot(122)
#  plt.scatter(coords[outer_mask, 0], coords[outer_mask, 1])
#  plt.show()
#
#  quit()






count_inner = np.count_nonzero(inner_mask)
count_outer = np.count_nonzero(outer_mask)

print("Inner:", count_inner)
print("Outer:", count_outer)

size = count_inner + count_outer

indent = "      "
print(indent+f"int sampleSize = {size};")
print()
print(indent+f"int indexBegin = 0;")
print(indent+f"int indexEnd = {count_inner};")
print()
print(indent+f"double coords[{size}][3] = {{")

for mask, count, is_last in [(inner_mask, count_inner, False), (outer_mask, count_outer, True)]:
    for i in range(count):
        if i == count - 1 and is_last:
            comma = ""
        else:
            comma = ","

        c = coords[mask][i]
        if c.shape[0] == 1:
            print(indent+f"  {{ {c[0]:14.8e}, 0., 0. }}" + comma)
        elif c.shape[0] == 2:
            print(indent+f"  {{ {c[0]:14.8e}, {c[1]:14.8e}, 0. }}" + comma)
        elif c.shape[0] == 3:
            print(indent+f"  {{ {c[0]:14.8e}, {c[1]:14.8e}, {c[2]:14.8e} }}" + comma)


print(indent+"};")
print()
print()


# safety check
ids_full = np.zeros(count_outer + count_inner, int)
ind = 0

print(indent+f"int ids[{size}] = {{")
for mask, count, is_last in [(inner_mask, count_inner, False), (outer_mask, count_outer, True)]:
    for i in range(count):
        if i == count - 1 and is_last:
            comma = ""
        else:
            comma = ","

        c = ids[mask][i]
        ids_full[ind] = c
        ind += 1
        print(indent+f"  {c}" + comma)

print(indent+"};")
print()
print()

uniques = np.unique(ids_full)
if uniques.shape != ids_full.shape:
    raise ValueError("Have non-unique particle IDs")



print(indent+f"double sml_init[{size}] = {{")
for mask, count, is_last in [(inner_mask, count_inner, False), (outer_mask, count_outer, True)]:
    for i in range(count):
        if i == count - 1 and is_last:
            comma = ""
        else:
            comma = ","

        s = sml_ic[mask][i]
        print(indent+f"  {s}" + comma)

print(indent+"};")
print()

print(indent+f"double sml_solution[{size}] = {{")
for mask, count, is_last in [(inner_mask, count_inner, False), (outer_mask, count_outer, True)]:
    for i in range(count):
        if i == count - 1 and is_last:
            comma = ""
        else:
            comma = ","

        s = sml_python[mask][i]
        print(indent+f"  {s}" + comma)

print(indent+"};")
print()

