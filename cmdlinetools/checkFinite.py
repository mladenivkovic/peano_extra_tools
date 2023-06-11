#!/usr/bin/env python3

# Check all available quantities of vtu/pvd files for NaNs/infs
# i.e. whether they are exclusively finite values.

# Usage: ./checkFinite.py
#    or  ./checkFinite.py <vtufile>
# <vtufile> : single .vtu file to plot
# by default, script will check all .vtu files.


import numpy as np
from peano4.toolbox.particles.postprocessing.ParticleVTUReader import (
    _clean_attribute_string,
    ParticleVTUReader,
)
import peano_extra_tools as pet


import sys, os

if len(sys.argv) > 1:
    vtufile = sys.argv[1]
    vtufilelist = [vtufile]
    if not os.path.exists(vtufile):
        raise FileNotFoundError("file '{0}' not found.".format(vtufile))

else:
    ls = os.listdir()
    vtufilelist = []
    for f in ls:
        if f.endswith(".vtu"):
            vtufilelist.append(f)

    if len(vtufilelist) == 0:
        raise FileNotFoundError("Found no .vtu file in this directory")


for vtufile in vtufilelist:
    reader = ParticleVTUReader(vtufile=vtufile, verbose=False)
    partData = reader.load()

    point_field_names = partData.get_attribute_list()

    first_field = getattr(partData, point_field_names[0])
    nparts_start = first_field.shape[0]

    print("Checking file {0} nparts = {1:d}".format(vtufile, nparts_start))

    for fieldname in point_field_names:
        attrname = _clean_attribute_string(fieldname)

        data = getattr(partData, attrname)

        # sanity checks
        nans = np.isnan(data)
        nnans = np.count_nonzero(nans)

        if nnans > 0:
            print("WARNING: FOUND", nnans, "NANS IN ATTRIBUTE", attrname)

        noninfs = np.isfinite(data)
        ninfs = np.count_nonzero(np.logical_not(noninfs))
        if ninfs > 0:
            print("WARNING: FOUND", ninfs, "INFS IN ATTRIBUTE", attrname)

        nparts = data.shape[0]
        if nparts != nparts_start:
            print("WARNING: FOUND", nparts, "PARTICLES, EXPECTED", nparts_start)


print("Done")
