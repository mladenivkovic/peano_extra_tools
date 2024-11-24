#pragma once

#include "InitialConditions.h"

namespace initialConditions {

  extern struct InitialConditions ICUniform3D;
  extern struct InitialConditions ICDisplaced3D_30neighbours;
  extern struct InitialConditions ICDisplaced3D_48neighbours;
  extern struct InitialConditions ICDisplaced3D_64neighbours;
  extern struct InitialConditions ICMultilevelDisplaced3D_30neighbours;
  extern struct InitialConditions ICMultilevelDisplaced3D_48neighbours;
  extern struct InitialConditions ICMultilevelDisplaced3D_64neighbours;

  struct InitialConditions getUniform3DIC(void);
  struct InitialConditions getDisplaced3DIC_30neighbours(void);
  struct InitialConditions getDisplaced3DIC_48neighbours(void);
  struct InitialConditions getDisplaced3DIC_64neighbours(void);
  struct InitialConditions getMultilevelDisplaced3DIC_30neighbours(void);
  struct InitialConditions getMultilevelDisplaced3DIC_48neighbours(void);
  struct InitialConditions getMultilevelDisplaced3DIC_64neighbours(void);

} // namespace initialConditions
