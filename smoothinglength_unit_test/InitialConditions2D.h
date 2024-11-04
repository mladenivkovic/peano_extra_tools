#pragma once

#include "InitialConditions.h"

namespace initialConditions {

  extern struct InitialConditions ICUniform2D;
  extern struct InitialConditions ICDisplaced2D;
  extern struct InitialConditions ICMultilevelDisplaced2D;

  struct InitialConditions getUniform2DIC(void);
  struct InitialConditions getDisplaced2DIC(void);
  struct InitialConditions getMultileveDisplaced2DIC(void);

} // namespace initialConditions
