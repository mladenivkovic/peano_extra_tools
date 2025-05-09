#!/usr/bin/env python3

errmsg="""
Print min/max values of particle fields.

Usage: python printMinMax.py particles-*.vtu
"""

import sys
from peano4.toolbox.particles.postprocessing.ParticleVTUReader import ParticleVTUReader


if len(sys.argv) < 2:
    raise ValueError("No files specified." + errmsg)


xmin_all = 1e300
ymin_all = 1e300
zmin_all = 1e300
vxmin_all = 1e300
vymin_all = 1e300
vzmin_all = 1e300
pmin_all = 1e300
rhomin_all = 1e300
umin_all = 1e300

xmax_all = -1e300
ymax_all = -1e300
zmax_all = -1e300
vxmax_all = -1e300
vymax_all = -1e300
vzmax_all = -1e300
pmax_all = -1e300
rhomax_all = -1e300
umax_all = -1e300



for f in sys.argv[1:]:

    if not f.endswith(".vtu"):
        print(f"File {f} is not a .vtu file, skipping.")
        continue

    reader = ParticleVTUReader(vtufile=f)
    partData = reader.load()
    #  time = reader.get_snapshot_time()

    # show me what particle fields are stored
    #  partData.show_attribute_list()

    x = partData.x[:, 0]
    xmin = x.min()
    xmax = x.max()
    xmin_all = min(xmin_all, xmin)
    xmax_all = max(xmax_all, xmax)

    y = partData.x[:, 1]
    ymin = y.min()
    ymax = y.max()
    ymin_all = min(ymin_all, ymin)
    ymax_all = max(ymax_all, ymax)

    z = partData.x[:, 2]
    zmin = z.min()
    zmax = z.max()
    zmin_all = min(zmin_all, zmin)
    zmax_all = max(zmax_all, zmax)

    vx = partData.v[:, 0]
    vxmin = vx.min()
    vxmax = vx.max()
    vxmin_all = min(vxmin_all, vxmin)
    vxmax_all = max(vxmax_all, vxmax)

    vy = partData.v[:, 1]
    vymin = vy.min()
    vymax = vy.max()
    vymin_all = min(vymin_all, vymin)
    vymax_all = max(vymax_all, vymax)

    vz = partData.v[:, 2]
    vzmin = vz.min()
    vzmax = vz.max()
    vzmin_all = min(vzmin_all, vzmin)
    vzmax_all = max(vzmax_all, vzmax)

    u = partData.u
    umin = u.min()
    umax = u.max()
    umin_all = min(umin_all, umin)
    umax_all = max(umax_all, umax)

    #  S = partData.S # doesn't exist yet?
    P = partData.pressure
    pmin = P.min()
    pmax = P.max()
    pmin_all = min(pmin_all, pmin)
    pmax_all = max(pmax_all, pmax)

    rho = partData.density
    rhomin = rho.min()
    rhomax = rho.max()
    rhomin_all = min(rhomin_all, rhomin)
    rhomax_all = max(rhomax_all, rhomax)


    print("File:", f)
    print("--- xmin=", xmin)
    print("--- xmax=", xmax)
    print("--- ymin=", ymin)
    print("--- ymax=", ymax)
    print("--- zmin=", zmin)
    print("--- zmax=", zmax)
    print("--- vxmin=", vxmin)
    print("--- vxmax=", vxmax)
    print("--- vymin=", vymin)
    print("--- vymax=", vymax)
    print("--- vzmin=", vzmin)
    print("--- vzmax=", vzmax)
    print("--- umin=", umin)
    print("--- umax=", umax)
    print("--- pmin=", pmin)
    print("--- pmax=", pmax)
    print("--- rhomin=", rhomin)
    print("--- rhomax=", rhomax)


print("----------------------------------------")
print("Global minmax:")
print("--- xmin=", xmin_all)
print("--- xmax=", xmax_all)
print("--- ymin=", ymin_all)
print("--- ymax=", ymax_all)
print("--- zmin=", zmin_all)
print("--- zmax=", zmax_all)
print("--- vxmin=", vxmin_all)
print("--- vxmax=", vxmax_all)
print("--- vymin=", vymin_all)
print("--- vymax=", vymax_all)
print("--- vzmin=", vzmin_all)
print("--- vzmax=", vzmax_all)
print("--- umin=", umin_all)
print("--- umax=", umax_all)
print("--- pmin=", pmin_all)
print("--- pmax=", pmax_all)
print("--- rhomin=", rhomin_all)
print("--- rhomax=", rhomax_all)


