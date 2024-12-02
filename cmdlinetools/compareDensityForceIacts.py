#!/usr/bin/env python3

# Read in and verify (temporary) debug output of density and force iacts.

# Density:

#  if (localParticle->getPartid() == 2143362927)
#    std::cout << "===== DENSITY PartID=" << localParticle->getPartid() <<
#      " iact with PartID=" << activeParticle->getPartid() <<
#      " r=" << r <<
#      " hi=" << hi <<
#      " Ri=" << iactR <<
#      " r/Ri=" << r/iactR <<
#      " iact?=" << (tarch::la::smaller(r, iactR) and tarch::la::greater(r, 0.0)) <<
#      " iactDensityCount=" << localParticle->getDensityNeighbourCount() <<
#      std::endl;

#  if (localParticle->getPartid() == 2143362927)
#    std::cout << "===== FORCE PartID=" << localParticle->getPartid() <<
#      " iact with PartID=" << activeParticle->getPartid() <<
#      " r=" << r <<
#      " hi=" << h_i <<
#      " hj=" << h_j <<
#      " Ri=" << iactRi <<
#      " Rj=" << iactRj <<
#      " r/Ri=" << r/iactRi <<
#      " r/Rj=" << r/iactRj <<
#      " iact?=" << ((tarch::la::smaller(r, iactRi) or (tarch::la::smaller(r, iactRj))) and tarch::la::greater(r, 0.0)) <<
#      " iactForceCount=" << localParticle->getForceNeighbourCount() <<
#      std::endl;


class part:

    def __init__(self, ID, r, hi, hj, Ri, Rj, rRi, rRj, iact_peano):
        self.ID = ID
        self.r = r
        self.hi = hi
        self.hj = hj
        self.Ri = Ri
        self.Rj = Rj
        self.rRi = rRi
        self.rRj = rRj

        self.iact_density = rRi < 1.0 and r > 0.
        if self.rRj is not None:
            self.iact_force = (rRi < 1.0 or rRi < 1.0) and r > 0.
        else:
            self.iact_force = None

        self.iact_peano = iact_peano

        return


def readfile(fname):

    f = open(fname, "r")
    lines = f.readlines()

    output = {}

    for l in lines:

        words = l.split(" ")
        if words[1] == "DENSITY":
            ID = int(words[5].strip("PartID="))
            r = float(words[6].strip("r="))
            h = float(words[7].strip("hi="))
            R = float(words[8].strip("Ri="))
            rRi = float(words[9].strip("r/Ri="))
            iact_peano = bool(words[10].strip("iact?="))

            p = part(ID, r, h, None, R, None, rRi, None, iact_peano)
            if ID in output:
                raise ValueError("Duplicate key in output dict")
            output[ID] = p


        elif words[1] == "FORCE":

            ID = int(words[5].strip("PartID="))
            r = float(words[6].strip("r="))
            hi = float(words[7].strip("hi="))
            hj = float(words[8].strip("hj="))
            Ri = float(words[9].strip("Ri="))
            Rj = float(words[10].strip("Rj="))
            rRi = float(words[11].strip("r/Ri="))
            rRj = float(words[12].strip("r/Rj="))
            iact_peano = bool(words[13].strip("iact?="))

            p = part(ID, r, hi, hj, Ri, Rj, rRi, rRj, iact_peano)

            if ID in output:
                raise ValueError("Duplicate key in output dict")
            output[ID] = p


    return output



if __name__ == "__main__":

    densdata = readfile("density")
    forcedata = readfile("force")

    if len(densdata) != len(forcedata):
        # should be equal if printout happened before the radius check
        print("Error: density and force loops not interacted with same amount of particles in total")
        print(len(densdata))
        print(len(forcedata))
        quit()

    error = False
    errcount = 0
    break_on_error = False

    for i in densdata.keys():

        pd = densdata[i]
        pf = forcedata[pd.ID]


        if pf.r != pd.r :
            print(f"Part {pd.ID} unequal radii: {pd.r}, {pf.r}")
            error = True

        if pf.hi != pd.hi :
            print(f"Part {pd.ID} unequal h: {pd.hi}, {pf.hi}")
            error = True

        if pf.Ri != pd.Ri :
            print(f"Part {pd.ID} unequal iact radii: {pd.Ri}, {pf.Ri}")
            error = True

        if pf.rRi != pd.rRi :
            print(f"Part {pd.ID} unequal r/Ri: {pd.rRi}, {pf.rRi}")
            error = True

        if pd.iact_density != pd.iact_peano:
            print(f"Part {pd.ID} unequal density iact bool: {pd.iact_density}, {pd.iact_peano}")
            error = True

        if pf.iact_force != pf.iact_peano:
            print(f"Part {pd.ID} unequal force iact bool: {pf.iact_force}, {pf.iact_peano}")
            error = True

        if error:
            errcount += 1

            if break_on_error:
                break
            else:
                print("----------------------------------------------------------")


    print(f"Finished with {errcount} errors.")



