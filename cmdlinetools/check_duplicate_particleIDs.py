#!/usr/bin/env python3

# Check for duplicate particle IDs

from peano4.toolbox.particles.postprocessing.ParticleVTUReader import ParticleVTUReader
import numpy as np
import sys
import os

vtufile = sys.argv[1]
if not os.path.exists(vtufile):
    raise FileNotFoundError("no file {}".format(vtufile))

reader = ParticleVTUReader(vtufile=vtufile, verbose=False)
partData = reader.load()
ids = partData.partid
ids = ids.astype(int)
ids = np.sort(ids)

print("First particle ID is", ids[0])

uniques, counts = np.unique(ids, return_counts=True)

if uniques.shape == ids.shape:
    print("All particle IDs are unique.")
else:
    mask = counts > 1

    ids_multi = uniques[mask]
    c_multi = counts[mask]

    for i in range(ids_multi.shape[0]):
        print(f"ID: {ids_multi[i]:12d} count:{c_multi[i]}")


print()

print(ids.shape)

for i in ids:
    print(i)
