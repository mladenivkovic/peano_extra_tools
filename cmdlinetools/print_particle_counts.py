#!/usr/bin/env python3

# Count how many particles you have in individual .vtu files

from peano4.toolbox.particles.postprocessing.ParticleVTUReader import ParticleVTUReader
import numpy as np

#  pvdfile = "output/snapshots/particles.pvd"
pvdfile = "particles.pvd"
reader = ParticleVTUReader(pvdfile=pvdfile, snapshot_time=0.0, verbose=False)
allfiles = reader.get_all_vtufiles()

for file in allfiles:
    partData = reader.read_single_vtu_file(file)
    #  partData.show_attribute_list()
    h = partData.smoothingLength
    x = partData.x
    v = partData.v
    m = partData.mass
    rho = partData.density
    print(
        "{0:20} particle count by x={1:6d} h={2:6d} v={3:6d} m={4:6d} rho={5:6d}".format(
            file, x.shape[0], h.shape[0], v.shape[0], m.shape[0], rho.shape[0]
        )
    )
