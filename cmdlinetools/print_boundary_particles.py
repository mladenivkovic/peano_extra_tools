#!/usr/bin/env python3

# Print out particles flagged as boundary particles.
# Usage: python3 print_boundary_particles.py <vtufile>

from peano4.toolbox.particles.postprocessing.ParticleVTUReader import ParticleVTUReader
import numpy as np
import sys
import os

vtufile = sys.argv[1]
if not os.path.exists(vtufile):
    raise FileNotFoundError("no file {}".format(vtufile))

reader = ParticleVTUReader(vtufile=vtufile, verbose=False)
partData = reader.load()
ids = partData.partid
ids = ids.astype(int)

isbp = partData.isBoundaryParticle
isbp = isbp.astype(bool)
print(isbp)
bp = ids[isbp]
bp.sort()

print("Boundary Particles:")
print(bp)


