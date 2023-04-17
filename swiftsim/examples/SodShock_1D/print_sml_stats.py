#!/usr/bin/env python3

# Print some smoothing length stats of all snapshots to screen

import swiftsimio
import sys, os
import numpy as np

def get_snapshot_list(snapshot_basename="sodShock", plot_all=True, snapnr=0):
    """
    Find the snapshot(s) that are to be plotted
    and return their names as list
    """

    snaplist = []

    if plot_all:
        dirlist = os.listdir()
        for f in dirlist:
            if f.startswith(snapshot_basename + "_") and f.endswith("hdf5"):
                snaplist.append(f)

        snaplist = sorted(snaplist)

    else:
        fname = snapshot_basename + "_" + str(snapnr).zfill(4) + ".hdf5"
        if not os.path.exists(fname):
            print("Didn't find file", fname)
            quit(1)
        snaplist.append(fname)

    return snaplist



#  fname = sys.argv[1]
snaplist = get_snapshot_list()

for snap in snaplist:
    data = swiftsimio.load(snap)

    h = data.gas.smoothing_lengths
    print("{0:20} h_min = {1:18.6f} h_max = {2:18.6f} h_av = {3:18.6f}".format(snap, h.min(), h.max(), np.mean(h)))

