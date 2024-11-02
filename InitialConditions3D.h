#pragma once

#include "InitialConditions.h"

namespace initialConditions {
  namespace threeDim {

    extern struct InitialConditions ICUniform3D;
    extern struct InitialConditions ICDisplaced3D;
    extern struct InitialConditions ICMultilevelDisplaced3D;

    struct InitialConditions getUniform3DIC(void);
    struct InitialConditions getDisplaced3DIC(void);
    struct InitialConditions getMultileveDisplaced3DIC(void);

  } // namespace threeDim
} // namespace initialConditions
