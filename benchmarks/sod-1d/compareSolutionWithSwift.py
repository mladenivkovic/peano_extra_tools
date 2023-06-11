#!/usr/bin/env python3

###############################################################################
# This file is part of SWIFT.
# Copyright (c) 2016 Matthieu Schaller (schaller@strw.leidenuniv.nl)
#               2019 Josh Borrow (josh.borrow@durham.ac.uk)
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
##############################################################################

# Compare the solutions that swift and peanoswift give.
# Usage: ./compareSolutionWithSwift.py <snapshot>
# <snapshot> should be snapshot index for swift


import sys
import os
import matplotlib

#  matplotlib.use("Agg")
from matplotlib import pyplot as plt
import h5py
from peano4.toolbox.particles.postprocessing.ParticleVTUReader import ParticleVTUReader


# Parameters
gas_gamma = 5.0 / 3.0  # Polytropic index
rho_L = 1.0  # Density left state
rho_R = 0.125  # Density right state
v_L = 0.0  # Velocity left state
v_R = 0.0  # Velocity right state
P_L = 1.0  # Pressure left state
P_R = 0.1  # Pressure right state


if len(sys.argv) < 2:
    snap = 52
else:
    snap = int(sys.argv[1])


# Get swift data
# -----------------------------------

swift_root = (
    "/home/mivkov/Durham/swiftsim/examples/HydroTests/SodShock_1D-unequalMasses"
)
output_basename = "sodShock_"

# Read the simulation data
fname_swift = output_basename + ("%04d.hdf5" % snap)
fullpath_swift = os.path.join(swift_root, fname_swift)
swiftsim = h5py.File(fullpath_swift, "r")
boxSize = swiftsim["/Header"].attrs["BoxSize"][0]
time = swiftsim["/Header"].attrs["Time"][0]
#  scheme = swiftsim["/HydroScheme"].attrs["Scheme"].decode("utf-8")
#  kernel = swiftsim["/HydroScheme"].attrs["Kernel function"].decode("utf-8")
#  neighbours = swiftsim["/HydroScheme"].attrs["Kernel target N_ngb"]
#  eta = swiftsim["/HydroScheme"].attrs["Kernel eta"]
#  git = swiftsim["Code"].attrs["Git Revision"].decode("utf-8")


x_swift = swiftsim["/PartType0/Coordinates"][:, 0]
v_swift = swiftsim["/PartType0/Velocities"][:, 0]
u_swift = swiftsim["/PartType0/InternalEnergies"][:]
S_swift = swiftsim["/PartType0/Entropies"][:]
P_swift = swiftsim["/PartType0/Pressures"][:]
rho_swift = swiftsim["/PartType0/Densities"][:]
m_swift = swiftsim["/PartType0/Masses"][:]
h_swift = swiftsim["/PartType0/SmoothingLengths"][:]
try:
    alpha_swift = sim["/PartType0/ViscosityParameters"][:]
    plot_alphaswift = True
except:
    plot_alpha = False
try:
    alpha_diff_swift = sim["PartType0/Diffusion"][:]
    plot_alpha_diff = True
except:
    plot_alpha_diff = False


# Get Peanoswift data
# -----------------------------------
pvdfile = "output/snapshots/particles.pvd"
if not os.path.exists(pvdfile):
    pvdfile = "particles.pvd"

reader = ParticleVTUReader(pvdfile=pvdfile, snapshot_time=time, verbose=False)
partData = reader.load()

# show me what particle fields are stored
partData.show_attribute_list()

x = partData.x[:, 0]
#  y = partData.x[:,1]
v = partData.v[:, 0]
u = partData.u
#  S = partData.S # doesn't exist yet?
P = partData.pressure
rho = partData.density
m = partData.mass
h = partData.smoothingLength

print("xdata:")
print("min", x.min(), "max", x.max())

x_min = 0.0
x_max = boxSize
if x.max() - x.min() > 1.1:
    x_max = 2.0

x += x_min


# Plot the interesting quantities
plt.figure(figsize=(7, 7 / 1.6))

rows = 3
cols = 2

peanokwargs = {
    "marker": ".",
    "color": "C0",
    "s": 4.0,
    "zorder": 4,
    "alpha": 0.6,
}

swiftkwargs = {
    "marker": ".",
    "color": "C1",
    "s": 4.0,
    "zorder": 2,
    "alpha": 0.6,
}

anakwargs = {
    "ls": "--",
    "color": "k",
    "alpha": 0.8,
    "lw": 1.2,
}


# Velocity profile --------------------------------
plt.subplot(rows, cols, 1)
plt.scatter(x, v, **peanokwargs)
plt.scatter(x_swift, v_swift, **swiftkwargs)
#  plt.plot(x_s, v_s, **anakwargs)
plt.xlabel("${\\rm{Position}}~x$", labelpad=0)
plt.ylabel("${\\rm{Velocity}}~v_x$", labelpad=0)
#  plt.xlim(-0.5, 0.5)
#  plt.ylim(-0.1, 0.95)

# Density profile --------------------------------
plt.subplot(rows, cols, 2)
#  if plot_alpha_diff:
#      plot(x, alpha_diff, ".", color="r", ms=4.0)
#      ylabel(r"${\rm{Diffusion}}~\alpha$", labelpad=0)
#      # Show location of contact discontinuity
#      plot([x_34, x_34], [-100, 100], color="k", alpha=0.5, ls="dashed", lw=1.2)
#      ylim(0, 1)
#  else:
plt.scatter(x, rho, label="Peano", **peanokwargs)
plt.scatter(x_swift, rho_swift, label="swift", **swiftkwargs)
#  plt.plot(x_s, rho_s, **anakwargs)
plt.ylabel("${\\rm{Density}}~\\rho$", labelpad=0)
plt.legend()
#  plt.ylim(0.05, 1.1)

plt.xlabel("${\\rm{Position}}~x$", labelpad=0)
#  plt.xlim(-0.5, 0.5)

# Pressure profile --------------------------------
plt.subplot(rows, cols, 3)
plt.scatter(x, P, **peanokwargs)
plt.scatter(x_swift, P_swift, **swiftkwargs)
#  plt.plot(x_s, P_s, **anakwargs)
plt.xlabel("${\\rm{Position}}~x$", labelpad=0)
plt.ylabel("${\\rm{Pressure}}~P$", labelpad=0)
#  plt.xlim(-0.5, 0.5)
#  plt.ylim(0.01, 1.1)

# Internal energy profile -------------------------
plt.subplot(rows, cols, 4)
plt.scatter(x, u, **peanokwargs)
plt.scatter(x_swift, u_swift, **swiftkwargs)
#  plt.plot(x_s, u_s, **anakwargs)
plt.xlabel("${\\rm{Position}}~x$", labelpad=0)
plt.ylabel("${\\rm{Internal~Energy}}~u$", labelpad=0)
#  plt.xlim(-0.5, 0.5)
#  plt.ylim(0.8, 2.2)

print("Size of x", x.shape)

# Mass profile --------------------------------
plt.subplot(rows, cols, 5)
plt.scatter(x, m, **peanokwargs)
plt.scatter(x_swift, m_swift, **swiftkwargs)
#  plt.plot(x_s, m_s, **anakwargs)
plt.xlabel("${\\rm{Position}}~x$", labelpad=0)
plt.ylabel("${\\rm{Masses}}~m$", labelpad=0)
#  plt.ylim(0.05, 1.1)

# Smoothing Length profile --------------------------------
plt.subplot(rows, cols, 6)
plt.scatter(x, h, **peanokwargs)
plt.scatter(x_swift, h_swift, **swiftkwargs)
#  plt.plot(x_s, h_s, **anakwargs)
plt.xlabel("${\\rm{Position}}~x$", labelpad=0)
plt.ylabel("${\\rm{Smoothing Length}}~h$", labelpad=0)
#  plt.ylim(0.05, 1.1)

plt.show()
quit()

# Entropy/alpha profile ---------------------------------
#  subplot(235)
#
#  if plot_alpha:
#      plot(x, alpha, ".", color="r", ms=4.0)
#      ylabel(r"${\rm{Viscosity}}~\alpha$", labelpad=0)
#      # Show location of shock
#      axvline(x=x_shock, color="k", alpha=0.5, ls="dashed", lw=1.2)
#      ylim(0, 1)
#  else:
#      plot(x, S, ".", color="r", ms=4.0)
#      plot(x_s, s_s, "--", color="k", alpha=0.8, lw=1.2)
#      ylabel("${\\rm{Entropy}}~S$", labelpad=0)
#      ylim(0.8, 3.8)

#  xlabel("${\\rm{Position}}~x$", labelpad=0)
#  xlim(-0.5, 0.5)

# Information -------------------------------------
#  subplot(236, frameon=False)
#
#  text_fontsize = 5
#
#  text(
#      -0.49,
#      0.9,
#      "Sod shock with  $\\gamma=%.3f$ in 1D at $t=%.2f$" % (gas_gamma, time),
#      fontsize=text_fontsize,
#  )
#  text(
#      -0.49,
#      0.8,
#      "Left: $(P_L, \\rho_L, v_L) = (%.3f, %.3f, %.3f)$" % (P_L, rho_L, v_L),
#      fontsize=text_fontsize,
#  )
#  text(
#      -0.49,
#      0.7,
#      "Right: $(P_R, \\rho_R, v_R) = (%.3f, %.3f, %.3f)$" % (P_R, rho_R, v_R),
#      fontsize=text_fontsize,
#  )
#  plot([-0.49, 0.1], [0.62, 0.62], "k-", lw=1)
#  text(-0.49, 0.5, "SWIFT %s" % git, fontsize=text_fontsize)
#  text(-0.49, 0.4, scheme, fontsize=text_fontsize)
#  text(-0.49, 0.3, kernel, fontsize=text_fontsize)
#  text(
#      -0.49,
#      0.2,
#      "$%.2f$ neighbours ($\\eta=%.3f$)" % (neighbours, eta),
#      fontsize=text_fontsize,
#  )
#  xlim(-0.5, 0.5)
#  ylim(0, 1)
#  xticks([])
#  yticks([])

plt.tight_layout()

plt.savefig("SodShock{0:.5f}.png".format(time), dpi=200)
