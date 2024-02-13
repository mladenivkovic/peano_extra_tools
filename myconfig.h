#pragma once

#ifndef HYDRO_DIMENSION
#pragma error "HYDRO_DIMENSION undefined. Make sure to define -DHYDRO_DIMENSION"
#endif

#ifndef Dimensions
#pragma error "Dimensions undefined. Make sure to define -DDimensions"
#endif

#define HYDRO_GAMMA_5_3

#define QUARTIC_SPLINE_KERNEL

#ifndef PeanoDebug
#define PeanoDebug 2
#endif
