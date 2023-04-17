###############################################################################
# This file is part of SWIFT.
# Copyright (c) 2016 Matthieu Schaller (schaller@strw.leidenuniv.nl)
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

import h5py
from numpy import *

# Generates a swift IC file for the 1D Sod Shock in a periodic box
# Forces equal distances between particles, at the price of unequal masses.

# Parameters
gamma = 5.0 / 3.0  # Gas adiabatic index
numPart = 900
numPart_L = numPart // 2
numPart_R = numPart // 2
x_min = -1.0
x_max = 1.0
rho_L = 1.0  # Density left state
rho_R = 0.125  # Density right state
v_L = 0.0  # Velocity left state
v_R = 0.0  # Velocity right state
P_L = 1.0  # Pressure left state
P_R = 0.1  # Pressure right state
fileName = "sodShock.hdf5"


# ---------------------------------------------------

# Find how many particles we actually have
boxSize = x_max - x_min
#  numPart = numPart_L + numPart_R

# Now get the distances
delta_L = (boxSize) / numPart
delta_R = (boxSize) / numPart
offset_L = delta_L / 2
offset_R = delta_R / 2

# Build the arrays
coords = zeros((numPart, 3))
v = zeros((numPart, 3))
ids = linspace(1, numPart, numPart)
m = zeros(numPart)
h = zeros(numPart)
u = zeros(numPart)

# Set the particles on the left
for i in range(numPart_L):
    coords[i, 0] = x_min + offset_L + i * delta_L
    u[i] = P_L / (rho_L * (gamma - 1.0))
    h[i] = 1.2348 * delta_L
    m[i] = boxSize * rho_L / (2.0 * numPart_L)
    v[i, 0] = v_L

# Set the particles on the right
for j in range(numPart_R):
    i = numPart_L + j
    coords[i, 0] = x_min + offset_L + i * delta_L
    u[i] = P_R / (rho_R * (gamma - 1.0))
    h[i] = 1.2348 * delta_R
    m[i] = boxSize * rho_R / (2.0 * numPart_R)
    v[i, 0] = v_R

# Shift particles
coords[:, 0] -= x_min
coords[:, 1] = 0.5

#  from matplotlib import pyplot as plt
#  plt.figure()
#  plt.subplot(2,2,1)
#  plt.scatter(coords[:,0], m)
#  plt.ylabel("Masses")
#
#  plt.subplot(2,2,2)
#  plt.scatter(coords[:,0], v[:,0])
#  plt.ylabel("velocity")
#
#  plt.subplot(2,2,3)
#  plt.scatter(coords[:,0], h)
#  plt.ylabel("sml")
#
#  plt.subplot(2,2,4)
#  plt.scatter(coords[:,0], u)
#  plt.ylabel("u")
#
#  plt.show()
#


# File
file = h5py.File(fileName, "w")

# Header
grp = file.create_group("/Header")
grp.attrs["BoxSize"] = boxSize
grp.attrs["NumPart_Total"] = [numPart, 0, 0, 0, 0, 0]
grp.attrs["NumPart_Total_HighWord"] = [0, 0, 0, 0, 0, 0]
grp.attrs["NumPart_ThisFile"] = [numPart, 0, 0, 0, 0, 0]
grp.attrs["Time"] = 0.0
grp.attrs["NumFilesPerSnapshot"] = 1
grp.attrs["MassTable"] = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
grp.attrs["Flag_Entropy_ICs"] = 0
grp.attrs["Dimension"] = 1

# Units
grp = file.create_group("/Units")
grp.attrs["Unit length in cgs (U_L)"] = 1.0
grp.attrs["Unit mass in cgs (U_M)"] = 1.0
grp.attrs["Unit time in cgs (U_t)"] = 1.0
grp.attrs["Unit current in cgs (U_I)"] = 1.0
grp.attrs["Unit temperature in cgs (U_T)"] = 1.0

# Particle group
grp = file.create_group("/PartType0")
grp.create_dataset("Coordinates", data=coords, dtype="d")
grp.create_dataset("Velocities", data=v, dtype="f")
grp.create_dataset("Masses", data=m, dtype="f")
grp.create_dataset("SmoothingLength", data=h, dtype="f")
grp.create_dataset("InternalEnergy", data=u, dtype="f")
grp.create_dataset("ParticleIDs", data=ids, dtype="L")


file.close()

x = coords[:,0]
print("xdata:")
print("min", x.min(), "max", x.max())

