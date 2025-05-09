#!/usr/bin/env python3

# Plot particle positions.

# Usage: ./plotPositions.py <pvdfile> or
#        ./plotPositions.py <vtufile>
#        ./plotPositions.py <time>
#
# <pvdfile> : plot all results of a .vtu file
# <vtufile> : single .vtu file to plot
# <time> : snapshot time to plot

import matplotlib

#  matplotlib.use("Agg")
from matplotlib import pyplot as plt
import numpy as np
import sys
import peano_extra_tools as pet


try:
    arg = sys.argv[1]
except IndexError:
    print("You need to provide me with either a valid .pvd or .vtu file name or a")
    print("snapshot time to read in as a cmdline argument. You gave me nothing.")
    quit()

is_file = pet.check_is_valid_file(arg)

if not is_file:
    is_time, time = pet.check_is_valid_time(arg)
else:
    is_time = False

if not is_file and not is_time:
    print("You need to provide me with either a valid .pvd or .vtu file name or a")
    print("snapshot time to read in as a cmdline argument. You gave me nothing.")
    quit()


def plot_positions(coords, title):

    fig = plt.figure(figsize=(6, 6), dpi=200)
    ax1 = fig.add_subplot(111)

    scatterkwargs = {
            "marker": ".",
            "s": 1,
            "edgecolor": None,
            "color": "k",
            }

    ax1.scatter(coords[:,0], coords[:,1], **scatterkwargs)
    ax1.set_xlabel("x")
    ax1.set_ylabel("y")
    ax1.set_title(str(title))

    fname = "positions-" + title + ".png"
    plt.savefig(fname)
    plt.close()
    print("Saved", fname)

    return





if is_file:
    is_vtu = False
    is_pvd = False
    if arg.endswith(".vtu"):
        is_vtu = True
    if arg.endswith(".pvd"):
        is_pvd = True

    if is_vtu:
        print("Plotting single vtu file")
        reader = pet.ParticleVTUReader(vtufile=arg, verbose=False)
        partData = reader.load()
        coords = partData.x[:,:2]
        plot_positions(coords, arg)

    elif is_pvd:
        print("Plotting all snapshots in pvd file")
        times = pet.ParticleVTUReader.get_snapshot_times(arg)
        for t in times:
            reader = pet.ParticleVTUReader(snapshot_time=t, pvdfile=arg, verbose=False)
            partData = reader.load()
            coords = partData.x[:,:2]
            plot_positions(coords, f"{t:.6f}")




if is_time:
    print("Plotting by time")
    # We have a valid time. Now read in the data now and return it.
    pvdfile = pet.guess_pvdfilename()

    reader = pet.ParticleVTUReader(snapshot_time=time, pvdfile=pvdfile, verbose=False)
    partData = reader.load()
    coords = partData.x[:,:2]
    plot_positions(coords, f"{time:.6f}")



