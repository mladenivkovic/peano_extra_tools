#!/usr/bin/env python3

# Plot all available quantities of vtu/pvd files

# Usage: ./plotAllQuantities2D.py <vtufile> or
#        ./plotAllQuantities2D.py <time>
# <vtufile> : single .vtu file to plot
# <time> : snapshot time to plot

import matplotlib

#  matplotlib.use("Agg")
from matplotlib import pyplot as plt
from mpl_toolkits.axes_grid1 import make_axes_locatable, axes_size
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


# Gather how many plots we're making
nplots = 0
for fieldname in point_field_names:
    # don't count coordinates for plots
    attrname = _clean_attribute_string(fieldname)
    if attrname == coordiante_fieldname:
        continue
    data = getattr(partData, attrname)

    if len(data.shape) == 1:
        nplots += 1
    elif len(data.shape) == 2:
        nplots += data.shape[1]
    else:
        raise IndexError("Don't know what to do here")

# Determine rows and columns
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
    "s": 1.0,
    "zorder": 1,
    "alpha": 1.0,
}


coords = getattr(partData, coordiante_fieldname)
x = coords[:, 0]
y = coords[:, 1]

print("Read in coordinates of", x.shape[0], "particles")
if x.shape[0] == 0:
    print("SOMETHING IS WRONG. I HAVE ZERO PARTICLES.")
    quit()


sbp = 1  # subplot counter

#  fig = plt.figure(dpi=300)
fig = plt.figure()


def add_cosmetics(ax, title):
    ax.set_xlabel("x")
    ax.set_ylabel("y")
    ax.set_title(title)


def add_colorbar(fig, ax, scatter):
    divider = make_axes_locatable(ax)
    cax = divider.append_axes("right", size="2%", pad=0.05)
    fig.colorbar(scatter, cax=cax)


# loop over all fields and plot them
for fieldname in point_field_names:
    attrname = _clean_attribute_string(fieldname)

    # skip coordinates
    if attrname == coordiante_fieldname:
        continue

    data = getattr(partData, attrname)

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
        ax = fig.add_subplot(nrows, ncols, sbp)
        sbp += 1
        sc = ax.scatter(x, y, c=data, **scatterkwargs)
        add_colorbar(fig, ax, sc)
        add_cosmetics(ax, attrname)

    # Multidimensional quantity
    elif len(data.shape) == 2:
        # loop over all dimensions
        for index in range(data.shape[1]):
            ax = fig.add_subplot(nrows, ncols, sbp)
            sbp += 1
            sc = ax.scatter(x, y, c=data[:, index], **scatterkwargs)
            add_colorbar(fig, ax, sc)
            add_cosmetics(ax, attrname + "[{0:d}]".format(index))

    else:
        raise IndexError("Don't know what to do here")


plt.show()
