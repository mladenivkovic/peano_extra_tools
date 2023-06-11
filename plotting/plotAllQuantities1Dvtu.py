#!/usr/bin/env python3

# Plot all available quantities of vtu/pvd files

# Usage: ./plotAllQuantities1D.py <vtufile> or
#        ./plotAllQuantities1D.py <time>
# <vtufile> : single .vtu file to plot
# <time> : snapshot time to plot

import matplotlib

#  matplotlib.use("Agg")
from matplotlib import pyplot as plt
import numpy as np
from peano4.toolbox.particles.postprocessing.ParticleVTUReader import (
    _clean_attribute_string,
)
import peano_extra_tools as pet


partData = pet.get_particle_data_from_time_or_vtufile()
point_field_names = partData.get_attribute_list()


# Make sure I know what the coordinates are
coordiante_fieldname = "x"
if "x" not in point_field_names:
    raise ValueError("Couldn't find coordinates (field 'x') in point_field_names")
else:
    print("Plotting Particle fields:")
    for field in point_field_names:
        print("    ", field)


# Determine rows and columns
nplots = len(point_field_names) - 1
av_plot_per_dim = np.sqrt(nplots)
nrows = int(av_plot_per_dim + 0.5)
ncols = int(av_plot_per_dim)

if nrows * ncols < nplots:
    ncols += 1
if nrows * ncols < nplots:
    print("WTF? Error")
    quit()

scatterkwargs = {
    "marker": ".",
    "s": 2.0,
    "zorder": 1,
    "alpha": 0.6,
}


coords = getattr(partData, coordiante_fieldname)
x = coords[:, 0]

print("Read in coordinates of", x.shape[0], "particles")
if x.shape[0] == 0:
    print("SOMETHING IS WRONG. I HAVE ZERO PARTICLES.")
    quit()


sbp = 1  # subplot counter
plt.figure()

for fieldname in point_field_names:
    attrname = _clean_attribute_string(fieldname)

    if attrname == coordiante_fieldname:
        continue

    data = getattr(partData, attrname)
    plt.subplot(nrows, ncols, sbp)
    plt.xlabel("x")
    plt.ylabel(attrname)

    # sanity checks
    nans = np.isnan(data)
    nnans = np.count_nonzero(nans)
    if nnans > 0:
        print("WARNIGN: FOUND", nnans, "NANS IN ATTRIBUTE", attrname)

    noninfs = np.isfinite(data)
    ninfs = np.count_nonzero(np.logical_not(noninfs))
    if ninfs > 0:
        print("WARNIGN: FOUND", ninfs, "INFS IN ATTRIBUTE", attrname)

    # One dimensional quantity
    if len(data.shape) == 1:
        plt.scatter(x, data, **scatterkwargs)

    # Multidimensional quantity
    elif len(data.shape) == 2:
        for index in range(data.shape[1]):
            plt.scatter(
                x, data[:, index], label="index {0:d}".format(index), **scatterkwargs
            )
        plt.legend()

    else:
        raise IndexError("Don't know what to do here")

    sbp += 1


plt.show()
