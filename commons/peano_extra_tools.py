#!/usr/bin/env python3

#======================================================
# A collection of commonly used tools and functions
# Intended to be imported, not to be run as-is.
#======================================================

import os
import sys

try:
    import peano4
    from peano4.toolbox.particles.postprocessing.ParticleVTUReader import ParticleVTUReader
except ImportError:
    print("You need to have access to the peano4 python modules. Import has failed. Add it to your pythonpath?")
    quit()

def _guess_pvdfilename():
    """
    try and select the default pvdfile.
    """
    pvdfile = "output/snapshots/particles.pvd"
    if not os.path.exists(pvdfile):
        pvdfile = "particles.pvd"
    if not os.path.exists(pvdfile):
        raise FileNotFoundError("Couldn't find default .pvd file.")
    return pvdfile

def check_is_valid_file(filename):
    """
    Check whether provided file name is valid.
    Used to check arguments passed by users, so may not be a string.
    Check for that too.
    """

    if not isinstance(filename, str):
        return False
    if os.path.exists(filename):
        return True
    return False


def check_is_valid_time(time):
    """
    Check if a provided cmd line arg is a valid time.
    If true, return time as float.
    If false, return original argument.
    """
    try:
        timefloat = float(time)
        return True, timefloat
    except ValueError:
        return False, time


def get_particle_data_from_time_or_vtufile(pvdfile=None):
    """
    Read in cmdline args. User needs to specify either a valid .vtu file name,
    or a time (which must be a float).

    Then either read the specific .vtu file, or all .vtu files associated with
    the snapshot time, and return the particleData.

    Optionally provide .pvd file name to read in, if user provides time as arg.
    Otherwise we'll take a guess.
    """

    try:
        arg = sys.argv[1]
    except IndexError:
        print("You need to provide me with either a valid .vtu file name or a")
        print("snapshot time to read in as a cmdline argument. You gave me nothing.")
        quit()


    has_time = False
    has_vtufile = check_is_valid_file(arg)
    if not has_vtufile:
        has_time, time = check_is_valid_time(arg)
        if not has_time:
            # I got neither the time nor a valid vtu file. Can't work like this.
            print("argument '", arg, "' is neither a file I could find nor a valid snapshot time.")
            quit(1)

        # We have a valid time. Now read in the data now and return it.
        if pvdfile is None:
            pvdfile = _guess_pvdfilename()

        reader = ParticleVTUReader(snapshot_time=time, pvdfile=pvdfile, verbose=False)

    else:
        # We have a valid vtu file name. Read that data in now and return it.
        reader = ParticleVTUReader(vtufile=arg, verbose=False)

    partData = reader.load()

    return partData
