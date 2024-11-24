#pragma once

#include "InitialConditions.h"

namespace initialConditions {

  extern struct InitialConditions ICUniform1D;
  extern struct InitialConditions ICDisplaced1D_3neighbours;
  extern struct InitialConditions ICDisplaced1D_5neighbours;
  extern struct InitialConditions ICDisplaced1D_10neighbours;
  extern struct InitialConditions ICMultilevelDisplaced1D_3neighbours;
  extern struct InitialConditions ICMultilevelDisplaced1D_5neighbours;
  extern struct InitialConditions ICMultilevelDisplaced1D_10neighbours;

  struct InitialConditions getUniform1DIC(void);

  struct InitialConditions getDisplaced1DIC_3neighbours(void);
  struct InitialConditions getDisplaced1DIC_5neighbours(void);
  struct InitialConditions getDisplaced1DIC_10neighbours(void);

  struct InitialConditions getMultileveDisplaced1DIC_3neighbours(void);
  struct InitialConditions getMultileveDisplaced1DIC_5neighbours(void);
  struct InitialConditions getMultileveDisplaced1DIC_10neighbours(void);

} // namespace initialConditions
