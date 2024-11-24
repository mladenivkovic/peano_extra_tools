#pragma once

#include "InitialConditions.h"

namespace initialConditions {

  extern struct InitialConditions ICUniform2D;
  extern struct InitialConditions ICDisplaced2D_8neighbours;
  extern struct InitialConditions ICDisplaced2D_15neighbours;
  extern struct InitialConditions ICDisplaced2D_20neighbours;
  extern struct InitialConditions ICMultilevelDisplaced2D_8neighbours;
  extern struct InitialConditions ICMultilevelDisplaced2D_15neighbours;
  extern struct InitialConditions ICMultilevelDisplaced2D_20neighbours;

  struct InitialConditions getUniform2DIC(void);
  struct InitialConditions getDisplaced2DIC_8neighbours(void);
  struct InitialConditions getDisplaced2DIC_15neighbours(void);
  struct InitialConditions getDisplaced2DIC_20neighbours(void);
  struct InitialConditions getMultilevelDisplaced2DIC_8neighbours(void);
  struct InitialConditions getMultilevelDisplaced2DIC_15neighbours(void);
  struct InitialConditions getMultilevelDisplaced2DIC_20neighbours(void);




} // namespace initialConditions
