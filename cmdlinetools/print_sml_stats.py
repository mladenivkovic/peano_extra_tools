#!/usr/bin/env python3

# Print some smoothing length stats to screen
# Reads in .pvd file, then gets stats for all
# vtu files tracked by the .pvd file


from peano4.toolbox.particles.postprocessing.ParticleVTUReader import ParticleVTUReader
import numpy as np
from peano_extra_tools import guess_pvdfilename

pvdfile = guess_pvdfilename()
reader = ParticleVTUReader(pvdfile=pvdfile, snapshot_time=0.0, verbose=False)
allfiles = reader.get_all_vtufiles()


for file in allfiles:
    partData = reader.read_single_vtu_file(file)
    #  partData.show_attribute_list()
    h = partData.smoothingLength
    print(
        "{0:20} h_min = {1:18.6f} h_max = {2:18.6f} h_av = {3:18.6f}".format(
            file, h.min(), h.max(), np.mean(h)
        )
    )
