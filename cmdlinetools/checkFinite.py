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

    vtufilelist.sort()


# get nr of particles in first file
vtufile = vtufilelist[0]
reader = ParticleVTUReader(vtufile=vtufile, verbose=False)
partData = reader.load()
point_field_names = partData.get_attribute_list()
first_field = getattr(partData, point_field_names[0])
nparts_start_sim = first_field.shape[0]


warn_inf = 0
warn_nan = 0
warn_npart = 0
warn_npart_file = 0

for vtufile in vtufilelist:
    reader = ParticleVTUReader(vtufile=vtufile, verbose=False)
    partData = reader.load()

    point_field_names = partData.get_attribute_list()

    first_field = getattr(partData, point_field_names[0])
    nparts_this_file = first_field.shape[0]

    print("Checking file {0} nparts = {1:d}".format(vtufile, nparts_this_file))
    if nparts_start_sim != nparts_this_file:
        print(
            "WARNING: THIS VTU FILE (",
            vtufile,
            ")HAS",
            nparts_this_file,
            "PARTICLES, EXPECTED",
            nparts_start_sim,
        )
        warn_npart += 1

    for fieldname in point_field_names:
        attrname = _clean_attribute_string(fieldname)

        data = getattr(partData, attrname)

        # sanity checks
        nans = np.isnan(data)
        nnans = np.count_nonzero(nans)

        if nnans > 0:
            print("WARNING: FOUND", nnans, "NANS IN ATTRIBUTE", attrname)
            warn_nan += 1

        noninfs = np.isfinite(data)
        ninfs = np.count_nonzero(np.logical_not(noninfs))
        if ninfs > 0:
            print("WARNING: FOUND", ninfs, "INFS IN ATTRIBUTE", attrname)
            warn_inf += 1

        nparts = data.shape[0]
        if nparts != nparts_this_file:
            print(
                "WARNING: THIS FIELD (",
                attrname,
                ")HAS",
                nparts,
                "PARTICLES, EXPECTED",
                nparts_this_file,
            )
            warn_npart_file += 1


print(
    "Done. Found {0:d} warnings: {1:d} infs, {2:d} NaNs, and {3:d} wrong particle counts".format(
        warn_nan + warn_inf + warn_npart + warn_npart_file,
        warn_inf,
        warn_nan,
        warn_npart,
        +warn_npart_file,
    )
)
