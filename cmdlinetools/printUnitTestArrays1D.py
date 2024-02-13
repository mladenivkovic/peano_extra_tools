#!/usr/bin/env python3


# -------------------------------------------
# Extract and print data for unit test
# -------------------------------------------


import h5py
from scipy.spatial import KDTree
import numpy as np
import sys
import os
import peano4
from peano4.toolbox.particles.postprocessing.ParticleVTUReader import ParticleVTUReader
import swift2.sphtools



#  file = "test_sml_1D.hdf5"
file = "test_sml_multiscale_1D.hdf5"
h_tolerance = 1.e-6
kernel = "quartic_spline"
ndim = 1

eta = 2.5819884616099626
nneigh = swift2.sphtools.number_of_neighbours_from_eta(
    eta, kernel=kernel, ndim=ndim
    )

# start and end of indexes of particle array to take
index_start = 0
index_end = 1000
#  index_start = 800
#  index_end = 850
size = index_end - index_start




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
random_seed = f["Header"].attrs["RandomSeed"]
f.close()


# Sort by particle ID
sort_ic = np.argsort(ids)
ids = ids[sort_ic]
coords = coords[sort_ic]
sml_ic = sml_ic[sort_ic]

ids = ids[index_start:index_end]
coords = coords[index_start:index_end, :]
sml_ic = sml_ic[index_start:index_end]


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


indent = "      "
print("=================================================================")


print()
filepath = os.path.join(os.getcwd(), file)
if filepath.startswith("/home/mivkov/Durham/"):
    filepath = filepath[len("/home/mivkov/Durham/"):]
print(indent+"// File: " + filepath)
print(indent+f"// Random Seed: {random_seed}")
print(indent+f"// IC particle index start: {index_start}")
print(indent+f"// IC particle index end: {index_end}")
print()

print(indent+f"int sampleSize = {size};")
print()
print(indent+f"int indexBegin = 10;")
print(indent+f"int indexEnd = {size-10};")
print()
print(indent+f"double coords[{size}][3] = {{")
#  for i in range(index_start, index_end):
for i in range(coords.shape[0]):
    if i != index_end - 1:
        comma = ","
    else:
        comma = ""

    c = coords[i]
    if c.shape[0] == 1:
        print(indent+f"  {{ {c[0]:14.8e}, 0., 0. }}" + comma)
    elif c.shape[0] == 2:
        print(indent+f"  {{ {c[0]:14.8e}, {c[1]:14.8e}, 0. }}" + comma)
    elif c.shape[0] == 3:
        print(indent+f"  {{ {c[0]:14.8e}, {c[1]:14.8e}, {c[2]:14.8e} }}" + comma)

print(indent+"};")
print()
print()

print(indent+f"int ids[{size}] = {{")
#  for i in range(index_start, index_end):
for i in range(coords.shape[0]):
    if i != index_end - 1:
        comma = ","
    else:
        comma = ""
    c = ids[i]
    print(indent+f"  {c}" + comma)

print(indent+"};")
print()
print()



print(indent+f"double sml_init[{size}] = {{")
#  for i in range(index_start, index_end):
for i in range(coords.shape[0]):
    if i != index_end - 1:
        comma = ","
    else:
        comma = ""
    s = sml_ic[i]
    print(indent+f"  {s}" + comma)

print(indent+"};")
print()

print(indent+f"double sml_solution[{size}] = {{")
#  for i in range(index_start, index_end):
for i in range(coords.shape[0]):
    if i != index_end - 1:
        comma = ","
    else:
        comma = ""
    s = sml_python[i]
    print(indent+f"  {s}" + comma)

print(indent+"};")
print()


