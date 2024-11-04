#!/usr/bin/env python3

import sys
import matplotlib

#  matplotlib.use("Agg")
from matplotlib import pyplot as plt
import numpy as np
import h5py
from peano4.toolbox.particles.postprocessing.ParticleVTUReader import ParticleVTUReader


scatterkwargs = {
    "s": 1.0,
    "alpha": 0.6,
    "marker": ".",
}


# ----------------------
# Original ICs
# ----------------------

gas_gamma = 5.0 / 3.0  # Polytropic index
rho_L = 1.0  # Density left state
rho_R = 0.125  # Density right state
v_L = 0.0  # Velocity left state
v_R = 0.0  # Velocity right state
P_L = 1.0  # Pressure left state
P_R = 0.1  # Pressure right state


def original_ic(x, center, leftVal, rightVal):
    """
    Get array of original initial conditions
    """
    res = np.zeros(x.shape)
    res[x < center] = leftVal
    res[x >= center] = rightVal
    return res


# ----------------------
# HDF5 ICs
# ----------------------

# Read the IC data from hdf5 file
sim = h5py.File("sodShock.hdf5", "r")
xhdf5 = sim["/PartType0/Coordinates"][:, 0]
vhdf5 = sim["/PartType0/Velocities"][:, 0]
uhdf5 = sim["/PartType0/InternalEnergy"][:]
masshdf5 = sim["/PartType0/Masses"][:]
#  S = sim["/PartType0/Entropies"][:]
#  P = sim["/PartType0/Pressures"][:]
#  rhoIC = sim["/PartType0/Masses"][:]

print("hdf5: u = 1.2:", np.count_nonzero(uhdf5 < 1.3))
print("hdf5: u = 1.5:", np.count_nonzero(uhdf5 > 1.3))


boxSize = sim["/Header"].attrs["BoxSize"]

center = 0.5 * boxSize

#  time = sim["/Header"].attrs["Time"][0]
#  scheme = sim["/HydroScheme"].attrs["Scheme"].decode("utf-8")
#  kernel = sim["/HydroScheme"].attrs["Kernel function"].decode("utf-8")
#  neighbours = sim["/HydroScheme"].attrs["Kernel target N_ngb"]
#  eta = sim["/HydroScheme"].attrs["Kernel eta"]
#  git = sim["Code"].attrs["Git Revision"].decode("utf-8")


# -----------------------------
# Peano4 ICs
# -----------------------------

#  pvdfile = "output/snapshots/particles.pvd"
pvdfile = "particles.pvd"
reader = ParticleVTUReader(pvdfile=pvdfile, snapshot_time=0.0, verbose=False)
partData = reader.load()

# show me what particle fields are stored
#  partData.show_attribute_list()

x = partData.x[:, 0]
#  y = partData.x[:,1]
v = partData.v[:, 0]
u = partData.u
#  S = partData.S # doesn't exist yet?
P = partData.pressure
rho = partData.density
mass = partData.mass


# ---------------------------------
# Plotting
# ---------------------------------

# Plot the interesting quantities
plt.figure(figsize=(7, 7 / 1.6))

rows = 2
cols = 3

xIC = np.linspace(0.0, boxSize, 200)
vIC = original_ic(xIC, center, v_L, v_R)
rhoIC = original_ic(xIC, center, rho_L, rho_R)
PIC = original_ic(xIC, center, P_L, P_R)


# Velocity profile --------------------------------
plt.subplot(rows, cols, 1)
plt.scatter(x, v, color="r", **scatterkwargs)
plt.scatter(xhdf5, vhdf5, color="g", **scatterkwargs)
plt.plot(xIC, vIC, "--", color="k", alpha=0.8, lw=1.2)
plt.xlabel("${\\rm{Position}}~x$", labelpad=0)
plt.ylabel("${\\rm{Velocity}}~v_x$", labelpad=0)
#  plt.xlim(-0.5, 0.5)
#  plt.ylim(-0.1, 0.95)

# Density profile --------------------------------
plt.subplot(rows, cols, 2)
plt.scatter(x, mass, color="r", **scatterkwargs)
plt.scatter(xhdf5, masshdf5, color="g", **scatterkwargs)
#  plt.plot(xIC, massIC, "--", color="k", alpha=0.8, lw=1.2)
plt.ylabel("${\\rm{Mass}}$", labelpad=0)
#  plt.ylim(0.05, 1.1)
plt.xlabel("${\\rm{Position}}~x$", labelpad=0)
#  plt.xlim(-0.5, 0.5)

# Pressure profile --------------------------------
plt.subplot(rows, cols, 3)
plt.scatter(x, P, color="r", **scatterkwargs)
#  plt.scatter(xhdf5, Phdf5, color="g", **scatterkwargs)
plt.plot(xIC, PIC, "--", color="k", alpha=0.8, lw=1.2)
plt.xlabel("${\\rm{Position}}~x$", labelpad=0)
plt.ylabel("${\\rm{Pressure}}~P$", labelpad=0)
#  plt.xlim(-0.5, 0.5)
#  plt.ylim(0.01, 1.1)

# Internal energy profile -------------------------
plt.subplot(rows, cols, 4)
plt.scatter(x, u, color="r", label="ICs Peano dump", **scatterkwargs)
plt.scatter(xhdf5, uhdf5, color="g", label="ICs in hdf5", **scatterkwargs)
#  plt.plot(xIC, uIC, "--", color="k", alpha=0.8, lw=1.2)
plt.xlabel("${\\rm{Position}}~x$", labelpad=0)
plt.ylabel("${\\rm{Internal~Energy}}~u$", labelpad=0)


# This used to be additional output from individual functions in peano
#  hdf5readerdata = np.loadtxt("HDF5ReaderParticleOutput.txt", dtype=float, delimiter=",")
#  xDebug1 = hdf5readerdata[:,2]
#  uDebug1 = hdf5readerdata[:,1]
#  plt.scatter(xDebug1, uDebug1, color="b", **scatterkwargs, label="HDF5 reader")
#
#  after_init_data = np.loadtxt("InsertParticlesFromHDF5File2Ooutput.txt", dtype=float, delimiter=",")
#  xDebug2 = after_init_data[:,2]
#  uDebug2 = after_init_data[:,1]
#  plt.scatter(xDebug2, uDebug2, color="y", label="InsertParticlesFromHDF5File", **scatterkwargs)
#  plt.xlim(-0.5, 0.5)
#  plt.ylim(0.8, 2.2)

plt.legend()

# Internal energy profile -------------------------
plt.subplot(rows, cols, 5)
plt.scatter(x, rho, color="r", **scatterkwargs)
#  plt.scatter(xhdf5, uhdf5, color="g", **scatterkwargs)
plt.plot(xIC, rhoIC, "--", color="k", alpha=0.8, lw=1.2)
plt.xlabel("${\\rm{Position}}~x$", labelpad=0)
plt.ylabel("${\\rm{Density}}~\\rho$", labelpad=0)
#  plt.xlim(-0.5, 0.5)
#  plt.ylim(0.8, 2.2)


plt.tight_layout()

#  plt.savefig("SodShock.png", dpi=200)
plt.show()
