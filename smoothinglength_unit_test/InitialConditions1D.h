#pragma once

#include "InitialConditions.h"

namespace initialConditions {

  extern struct InitialConditions ICUniform1D;
  extern struct InitialConditions ICDisplaced1D;
  extern struct InitialConditions ICMultilevelDisplaced1D;

  struct InitialConditions getUniform1DIC(void);
  struct InitialConditions getDisplaced1DIC(void);
  struct InitialConditions getMultileveDisplaced1DIC(void);

} // namespace initialConditions
