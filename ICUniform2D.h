#pragma once

#include <string>

namespace initialConditions {
  namespace twoDim {

    class ICUniform{

public:
      std::string name = "2D Uniform";

      // File: Peano/tests/swift2/test-smoothing-length-computation/test-smoothing-length-computation-2D/test_sml_2D.hdf5
      // Random Seed: 4989
      // Kernel: quartic_spline
      // size of box for selected particles: 0.15
      // size of box surrounding selected particles ('boundary particles'): 0.4

      int sampleSize = 256;

      int indexBegin = 0;
      int indexEnd = 36;

      double h_tolerance = 1e-06;
      double resolution_eta = 1.2761313865909358;

      double h_min = 0.06382029811594069;
      double h_max = 0.08910551922544047;

      double coords[256][3] = {
        { 3.75000000e-01, 3.75000000e-01, 0.00000000e+00 },
        { 3.75000000e-01, 4.25000000e-01, 0.00000000e+00 },
        { 3.75000000e-01, 4.75000000e-01, 0.00000000e+00 },
        { 3.75000000e-01, 5.25000000e-01, 0.00000000e+00 },
        { 3.75000000e-01, 5.75000000e-01, 0.00000000e+00 },
        { 3.75000000e-01, 6.25000000e-01, 0.00000000e+00 },
        { 4.25000000e-01, 3.75000000e-01, 0.00000000e+00 },
        { 4.25000000e-01, 4.25000000e-01, 0.00000000e+00 },
        { 4.25000000e-01, 4.75000000e-01, 0.00000000e+00 },
        { 4.25000000e-01, 5.25000000e-01, 0.00000000e+00 },
        { 4.25000000e-01, 5.75000000e-01, 0.00000000e+00 },
        { 4.25000000e-01, 6.25000000e-01, 0.00000000e+00 },
        { 4.75000000e-01, 3.75000000e-01, 0.00000000e+00 },
        { 4.75000000e-01, 4.25000000e-01, 0.00000000e+00 },
        { 4.75000000e-01, 4.75000000e-01, 0.00000000e+00 },
        { 4.75000000e-01, 5.25000000e-01, 0.00000000e+00 },
        { 4.75000000e-01, 5.75000000e-01, 0.00000000e+00 },
        { 4.75000000e-01, 6.25000000e-01, 0.00000000e+00 },
        { 5.25000000e-01, 3.75000000e-01, 0.00000000e+00 },
        { 5.25000000e-01, 4.25000000e-01, 0.00000000e+00 },
        { 5.25000000e-01, 4.75000000e-01, 0.00000000e+00 },
        { 5.25000000e-01, 5.25000000e-01, 0.00000000e+00 },
        { 5.25000000e-01, 5.75000000e-01, 0.00000000e+00 },
        { 5.25000000e-01, 6.25000000e-01, 0.00000000e+00 },
        { 5.75000000e-01, 3.75000000e-01, 0.00000000e+00 },
        { 5.75000000e-01, 4.25000000e-01, 0.00000000e+00 },
        { 5.75000000e-01, 4.75000000e-01, 0.00000000e+00 },
        { 5.75000000e-01, 5.25000000e-01, 0.00000000e+00 },
        { 5.75000000e-01, 5.75000000e-01, 0.00000000e+00 },
        { 5.75000000e-01, 6.25000000e-01, 0.00000000e+00 },
        { 6.25000000e-01, 3.75000000e-01, 0.00000000e+00 },
        { 6.25000000e-01, 4.25000000e-01, 0.00000000e+00 },
        { 6.25000000e-01, 4.75000000e-01, 0.00000000e+00 },
        { 6.25000000e-01, 5.25000000e-01, 0.00000000e+00 },
        { 6.25000000e-01, 5.75000000e-01, 0.00000000e+00 },
        { 6.25000000e-01, 6.25000000e-01, 0.00000000e+00 },
        { 1.25000000e-01, 1.25000000e-01, 0.00000000e+00 },
        { 1.25000000e-01, 1.75000000e-01, 0.00000000e+00 },
        { 1.25000000e-01, 2.25000000e-01, 0.00000000e+00 },
        { 1.25000000e-01, 2.75000000e-01, 0.00000000e+00 },
        { 1.25000000e-01, 3.25000000e-01, 0.00000000e+00 },
        { 1.25000000e-01, 3.75000000e-01, 0.00000000e+00 },
        { 1.25000000e-01, 4.25000000e-01, 0.00000000e+00 },
        { 1.25000000e-01, 4.75000000e-01, 0.00000000e+00 },
        { 1.25000000e-01, 5.25000000e-01, 0.00000000e+00 },
        { 1.25000000e-01, 5.75000000e-01, 0.00000000e+00 },
        { 1.25000000e-01, 6.25000000e-01, 0.00000000e+00 },
        { 1.25000000e-01, 6.75000000e-01, 0.00000000e+00 },
        { 1.25000000e-01, 7.25000000e-01, 0.00000000e+00 },
        { 1.25000000e-01, 7.75000000e-01, 0.00000000e+00 },
        { 1.25000000e-01, 8.25000000e-01, 0.00000000e+00 },
        { 1.25000000e-01, 8.75000000e-01, 0.00000000e+00 },
        { 1.75000000e-01, 1.25000000e-01, 0.00000000e+00 },
        { 1.75000000e-01, 1.75000000e-01, 0.00000000e+00 },
        { 1.75000000e-01, 2.25000000e-01, 0.00000000e+00 },
        { 1.75000000e-01, 2.75000000e-01, 0.00000000e+00 },
        { 1.75000000e-01, 3.25000000e-01, 0.00000000e+00 },
        { 1.75000000e-01, 3.75000000e-01, 0.00000000e+00 },
        { 1.75000000e-01, 4.25000000e-01, 0.00000000e+00 },
        { 1.75000000e-01, 4.75000000e-01, 0.00000000e+00 },
        { 1.75000000e-01, 5.25000000e-01, 0.00000000e+00 },
        { 1.75000000e-01, 5.75000000e-01, 0.00000000e+00 },
        { 1.75000000e-01, 6.25000000e-01, 0.00000000e+00 },
        { 1.75000000e-01, 6.75000000e-01, 0.00000000e+00 },
        { 1.75000000e-01, 7.25000000e-01, 0.00000000e+00 },
        { 1.75000000e-01, 7.75000000e-01, 0.00000000e+00 },
        { 1.75000000e-01, 8.25000000e-01, 0.00000000e+00 },
        { 1.75000000e-01, 8.75000000e-01, 0.00000000e+00 },
        { 2.25000000e-01, 1.25000000e-01, 0.00000000e+00 },
        { 2.25000000e-01, 1.75000000e-01, 0.00000000e+00 },
        { 2.25000000e-01, 2.25000000e-01, 0.00000000e+00 },
        { 2.25000000e-01, 2.75000000e-01, 0.00000000e+00 },
        { 2.25000000e-01, 3.25000000e-01, 0.00000000e+00 },
        { 2.25000000e-01, 3.75000000e-01, 0.00000000e+00 },
        { 2.25000000e-01, 4.25000000e-01, 0.00000000e+00 },
        { 2.25000000e-01, 4.75000000e-01, 0.00000000e+00 },
        { 2.25000000e-01, 5.25000000e-01, 0.00000000e+00 },
        { 2.25000000e-01, 5.75000000e-01, 0.00000000e+00 },
        { 2.25000000e-01, 6.25000000e-01, 0.00000000e+00 },
        { 2.25000000e-01, 6.75000000e-01, 0.00000000e+00 },
        { 2.25000000e-01, 7.25000000e-01, 0.00000000e+00 },
        { 2.25000000e-01, 7.75000000e-01, 0.00000000e+00 },
        { 2.25000000e-01, 8.25000000e-01, 0.00000000e+00 },
        { 2.25000000e-01, 8.75000000e-01, 0.00000000e+00 },
        { 2.75000000e-01, 1.25000000e-01, 0.00000000e+00 },
        { 2.75000000e-01, 1.75000000e-01, 0.00000000e+00 },
        { 2.75000000e-01, 2.25000000e-01, 0.00000000e+00 },
        { 2.75000000e-01, 2.75000000e-01, 0.00000000e+00 },
        { 2.75000000e-01, 3.25000000e-01, 0.00000000e+00 },
        { 2.75000000e-01, 3.75000000e-01, 0.00000000e+00 },
        { 2.75000000e-01, 4.25000000e-01, 0.00000000e+00 },
        { 2.75000000e-01, 4.75000000e-01, 0.00000000e+00 },
        { 2.75000000e-01, 5.25000000e-01, 0.00000000e+00 },
        { 2.75000000e-01, 5.75000000e-01, 0.00000000e+00 },
        { 2.75000000e-01, 6.25000000e-01, 0.00000000e+00 },
        { 2.75000000e-01, 6.75000000e-01, 0.00000000e+00 },
        { 2.75000000e-01, 7.25000000e-01, 0.00000000e+00 },
        { 2.75000000e-01, 7.75000000e-01, 0.00000000e+00 },
        { 2.75000000e-01, 8.25000000e-01, 0.00000000e+00 },
        { 2.75000000e-01, 8.75000000e-01, 0.00000000e+00 },
        { 3.25000000e-01, 1.25000000e-01, 0.00000000e+00 },
        { 3.25000000e-01, 1.75000000e-01, 0.00000000e+00 },
        { 3.25000000e-01, 2.25000000e-01, 0.00000000e+00 },
        { 3.25000000e-01, 2.75000000e-01, 0.00000000e+00 },
        { 3.25000000e-01, 3.25000000e-01, 0.00000000e+00 },
        { 3.25000000e-01, 3.75000000e-01, 0.00000000e+00 },
        { 3.25000000e-01, 4.25000000e-01, 0.00000000e+00 },
        { 3.25000000e-01, 4.75000000e-01, 0.00000000e+00 },
        { 3.25000000e-01, 5.25000000e-01, 0.00000000e+00 },
        { 3.25000000e-01, 5.75000000e-01, 0.00000000e+00 },
        { 3.25000000e-01, 6.25000000e-01, 0.00000000e+00 },
        { 3.25000000e-01, 6.75000000e-01, 0.00000000e+00 },
        { 3.25000000e-01, 7.25000000e-01, 0.00000000e+00 },
        { 3.25000000e-01, 7.75000000e-01, 0.00000000e+00 },
        { 3.25000000e-01, 8.25000000e-01, 0.00000000e+00 },
        { 3.25000000e-01, 8.75000000e-01, 0.00000000e+00 },
        { 3.75000000e-01, 1.25000000e-01, 0.00000000e+00 },
        { 3.75000000e-01, 1.75000000e-01, 0.00000000e+00 },
        { 3.75000000e-01, 2.25000000e-01, 0.00000000e+00 },
        { 3.75000000e-01, 2.75000000e-01, 0.00000000e+00 },
        { 3.75000000e-01, 3.25000000e-01, 0.00000000e+00 },
        { 3.75000000e-01, 6.75000000e-01, 0.00000000e+00 },
        { 3.75000000e-01, 7.25000000e-01, 0.00000000e+00 },
        { 3.75000000e-01, 7.75000000e-01, 0.00000000e+00 },
        { 3.75000000e-01, 8.25000000e-01, 0.00000000e+00 },
        { 3.75000000e-01, 8.75000000e-01, 0.00000000e+00 },
        { 4.25000000e-01, 1.25000000e-01, 0.00000000e+00 },
        { 4.25000000e-01, 1.75000000e-01, 0.00000000e+00 },
        { 4.25000000e-01, 2.25000000e-01, 0.00000000e+00 },
        { 4.25000000e-01, 2.75000000e-01, 0.00000000e+00 },
        { 4.25000000e-01, 3.25000000e-01, 0.00000000e+00 },
        { 4.25000000e-01, 6.75000000e-01, 0.00000000e+00 },
        { 4.25000000e-01, 7.25000000e-01, 0.00000000e+00 },
        { 4.25000000e-01, 7.75000000e-01, 0.00000000e+00 },
        { 4.25000000e-01, 8.25000000e-01, 0.00000000e+00 },
        { 4.25000000e-01, 8.75000000e-01, 0.00000000e+00 },
        { 4.75000000e-01, 1.25000000e-01, 0.00000000e+00 },
        { 4.75000000e-01, 1.75000000e-01, 0.00000000e+00 },
        { 4.75000000e-01, 2.25000000e-01, 0.00000000e+00 },
        { 4.75000000e-01, 2.75000000e-01, 0.00000000e+00 },
        { 4.75000000e-01, 3.25000000e-01, 0.00000000e+00 },
        { 4.75000000e-01, 6.75000000e-01, 0.00000000e+00 },
        { 4.75000000e-01, 7.25000000e-01, 0.00000000e+00 },
        { 4.75000000e-01, 7.75000000e-01, 0.00000000e+00 },
        { 4.75000000e-01, 8.25000000e-01, 0.00000000e+00 },
        { 4.75000000e-01, 8.75000000e-01, 0.00000000e+00 },
        { 5.25000000e-01, 1.25000000e-01, 0.00000000e+00 },
        { 5.25000000e-01, 1.75000000e-01, 0.00000000e+00 },
        { 5.25000000e-01, 2.25000000e-01, 0.00000000e+00 },
        { 5.25000000e-01, 2.75000000e-01, 0.00000000e+00 },
        { 5.25000000e-01, 3.25000000e-01, 0.00000000e+00 },
        { 5.25000000e-01, 6.75000000e-01, 0.00000000e+00 },
        { 5.25000000e-01, 7.25000000e-01, 0.00000000e+00 },
        { 5.25000000e-01, 7.75000000e-01, 0.00000000e+00 },
        { 5.25000000e-01, 8.25000000e-01, 0.00000000e+00 },
        { 5.25000000e-01, 8.75000000e-01, 0.00000000e+00 },
        { 5.75000000e-01, 1.25000000e-01, 0.00000000e+00 },
        { 5.75000000e-01, 1.75000000e-01, 0.00000000e+00 },
        { 5.75000000e-01, 2.25000000e-01, 0.00000000e+00 },
        { 5.75000000e-01, 2.75000000e-01, 0.00000000e+00 },
        { 5.75000000e-01, 3.25000000e-01, 0.00000000e+00 },
        { 5.75000000e-01, 6.75000000e-01, 0.00000000e+00 },
        { 5.75000000e-01, 7.25000000e-01, 0.00000000e+00 },
        { 5.75000000e-01, 7.75000000e-01, 0.00000000e+00 },
        { 5.75000000e-01, 8.25000000e-01, 0.00000000e+00 },
        { 5.75000000e-01, 8.75000000e-01, 0.00000000e+00 },
        { 6.25000000e-01, 1.25000000e-01, 0.00000000e+00 },
        { 6.25000000e-01, 1.75000000e-01, 0.00000000e+00 },
        { 6.25000000e-01, 2.25000000e-01, 0.00000000e+00 },
        { 6.25000000e-01, 2.75000000e-01, 0.00000000e+00 },
        { 6.25000000e-01, 3.25000000e-01, 0.00000000e+00 },
        { 6.25000000e-01, 6.75000000e-01, 0.00000000e+00 },
        { 6.25000000e-01, 7.25000000e-01, 0.00000000e+00 },
        { 6.25000000e-01, 7.75000000e-01, 0.00000000e+00 },
        { 6.25000000e-01, 8.25000000e-01, 0.00000000e+00 },
        { 6.25000000e-01, 8.75000000e-01, 0.00000000e+00 },
        { 6.75000000e-01, 1.25000000e-01, 0.00000000e+00 },
        { 6.75000000e-01, 1.75000000e-01, 0.00000000e+00 },
        { 6.75000000e-01, 2.25000000e-01, 0.00000000e+00 },
        { 6.75000000e-01, 2.75000000e-01, 0.00000000e+00 },
        { 6.75000000e-01, 3.25000000e-01, 0.00000000e+00 },
        { 6.75000000e-01, 3.75000000e-01, 0.00000000e+00 },
        { 6.75000000e-01, 4.25000000e-01, 0.00000000e+00 },
        { 6.75000000e-01, 4.75000000e-01, 0.00000000e+00 },
        { 6.75000000e-01, 5.25000000e-01, 0.00000000e+00 },
        { 6.75000000e-01, 5.75000000e-01, 0.00000000e+00 },
        { 6.75000000e-01, 6.25000000e-01, 0.00000000e+00 },
        { 6.75000000e-01, 6.75000000e-01, 0.00000000e+00 },
        { 6.75000000e-01, 7.25000000e-01, 0.00000000e+00 },
        { 6.75000000e-01, 7.75000000e-01, 0.00000000e+00 },
        { 6.75000000e-01, 8.25000000e-01, 0.00000000e+00 },
        { 6.75000000e-01, 8.75000000e-01, 0.00000000e+00 },
        { 7.25000000e-01, 1.25000000e-01, 0.00000000e+00 },
        { 7.25000000e-01, 1.75000000e-01, 0.00000000e+00 },
        { 7.25000000e-01, 2.25000000e-01, 0.00000000e+00 },
        { 7.25000000e-01, 2.75000000e-01, 0.00000000e+00 },
        { 7.25000000e-01, 3.25000000e-01, 0.00000000e+00 },
        { 7.25000000e-01, 3.75000000e-01, 0.00000000e+00 },
        { 7.25000000e-01, 4.25000000e-01, 0.00000000e+00 },
        { 7.25000000e-01, 4.75000000e-01, 0.00000000e+00 },
        { 7.25000000e-01, 5.25000000e-01, 0.00000000e+00 },
        { 7.25000000e-01, 5.75000000e-01, 0.00000000e+00 },
        { 7.25000000e-01, 6.25000000e-01, 0.00000000e+00 },
        { 7.25000000e-01, 6.75000000e-01, 0.00000000e+00 },
        { 7.25000000e-01, 7.25000000e-01, 0.00000000e+00 },
        { 7.25000000e-01, 7.75000000e-01, 0.00000000e+00 },
        { 7.25000000e-01, 8.25000000e-01, 0.00000000e+00 },
        { 7.25000000e-01, 8.75000000e-01, 0.00000000e+00 },
        { 7.75000000e-01, 1.25000000e-01, 0.00000000e+00 },
        { 7.75000000e-01, 1.75000000e-01, 0.00000000e+00 },
        { 7.75000000e-01, 2.25000000e-01, 0.00000000e+00 },
        { 7.75000000e-01, 2.75000000e-01, 0.00000000e+00 },
        { 7.75000000e-01, 3.25000000e-01, 0.00000000e+00 },
        { 7.75000000e-01, 3.75000000e-01, 0.00000000e+00 },
        { 7.75000000e-01, 4.25000000e-01, 0.00000000e+00 },
        { 7.75000000e-01, 4.75000000e-01, 0.00000000e+00 },
        { 7.75000000e-01, 5.25000000e-01, 0.00000000e+00 },
        { 7.75000000e-01, 5.75000000e-01, 0.00000000e+00 },
        { 7.75000000e-01, 6.25000000e-01, 0.00000000e+00 },
        { 7.75000000e-01, 6.75000000e-01, 0.00000000e+00 },
        { 7.75000000e-01, 7.25000000e-01, 0.00000000e+00 },
        { 7.75000000e-01, 7.75000000e-01, 0.00000000e+00 },
        { 7.75000000e-01, 8.25000000e-01, 0.00000000e+00 },
        { 7.75000000e-01, 8.75000000e-01, 0.00000000e+00 },
        { 8.25000000e-01, 1.25000000e-01, 0.00000000e+00 },
        { 8.25000000e-01, 1.75000000e-01, 0.00000000e+00 },
        { 8.25000000e-01, 2.25000000e-01, 0.00000000e+00 },
        { 8.25000000e-01, 2.75000000e-01, 0.00000000e+00 },
        { 8.25000000e-01, 3.25000000e-01, 0.00000000e+00 },
        { 8.25000000e-01, 3.75000000e-01, 0.00000000e+00 },
        { 8.25000000e-01, 4.25000000e-01, 0.00000000e+00 },
        { 8.25000000e-01, 4.75000000e-01, 0.00000000e+00 },
        { 8.25000000e-01, 5.25000000e-01, 0.00000000e+00 },
        { 8.25000000e-01, 5.75000000e-01, 0.00000000e+00 },
        { 8.25000000e-01, 6.25000000e-01, 0.00000000e+00 },
        { 8.25000000e-01, 6.75000000e-01, 0.00000000e+00 },
        { 8.25000000e-01, 7.25000000e-01, 0.00000000e+00 },
        { 8.25000000e-01, 7.75000000e-01, 0.00000000e+00 },
        { 8.25000000e-01, 8.25000000e-01, 0.00000000e+00 },
        { 8.25000000e-01, 8.75000000e-01, 0.00000000e+00 },
        { 8.75000000e-01, 1.25000000e-01, 0.00000000e+00 },
        { 8.75000000e-01, 1.75000000e-01, 0.00000000e+00 },
        { 8.75000000e-01, 2.25000000e-01, 0.00000000e+00 },
        { 8.75000000e-01, 2.75000000e-01, 0.00000000e+00 },
        { 8.75000000e-01, 3.25000000e-01, 0.00000000e+00 },
        { 8.75000000e-01, 3.75000000e-01, 0.00000000e+00 },
        { 8.75000000e-01, 4.25000000e-01, 0.00000000e+00 },
        { 8.75000000e-01, 4.75000000e-01, 0.00000000e+00 },
        { 8.75000000e-01, 5.25000000e-01, 0.00000000e+00 },
        { 8.75000000e-01, 5.75000000e-01, 0.00000000e+00 },
        { 8.75000000e-01, 6.25000000e-01, 0.00000000e+00 },
        { 8.75000000e-01, 6.75000000e-01, 0.00000000e+00 },
        { 8.75000000e-01, 7.25000000e-01, 0.00000000e+00 },
        { 8.75000000e-01, 7.75000000e-01, 0.00000000e+00 },
        { 8.75000000e-01, 8.25000000e-01, 0.00000000e+00 },
        { 8.75000000e-01, 8.75000000e-01, 0.00000000e+00 }
      };


      int ids[256] = {
        148,
        149,
        150,
        151,
        152,
        153,
        168,
        169,
        170,
        171,
        172,
        173,
        188,
        189,
        190,
        191,
        192,
        193,
        208,
        209,
        210,
        211,
        212,
        213,
        228,
        229,
        230,
        231,
        232,
        233,
        248,
        249,
        250,
        251,
        252,
        253,
        43,
        44,
        45,
        46,
        47,
        48,
        49,
        50,
        51,
        52,
        53,
        54,
        55,
        56,
        57,
        58,
        63,
        64,
        65,
        66,
        67,
        68,
        69,
        70,
        71,
        72,
        73,
        74,
        75,
        76,
        77,
        78,
        83,
        84,
        85,
        86,
        87,
        88,
        89,
        90,
        91,
        92,
        93,
        94,
        95,
        96,
        97,
        98,
        103,
        104,
        105,
        106,
        107,
        108,
        109,
        110,
        111,
        112,
        113,
        114,
        115,
        116,
        117,
        118,
        123,
        124,
        125,
        126,
        127,
        128,
        129,
        130,
        131,
        132,
        133,
        134,
        135,
        136,
        137,
        138,
        143,
        144,
        145,
        146,
        147,
        154,
        155,
        156,
        157,
        158,
        163,
        164,
        165,
        166,
        167,
        174,
        175,
        176,
        177,
        178,
        183,
        184,
        185,
        186,
        187,
        194,
        195,
        196,
        197,
        198,
        203,
        204,
        205,
        206,
        207,
        214,
        215,
        216,
        217,
        218,
        223,
        224,
        225,
        226,
        227,
        234,
        235,
        236,
        237,
        238,
        243,
        244,
        245,
        246,
        247,
        254,
        255,
        256,
        257,
        258,
        263,
        264,
        265,
        266,
        267,
        268,
        269,
        270,
        271,
        272,
        273,
        274,
        275,
        276,
        277,
        278,
        283,
        284,
        285,
        286,
        287,
        288,
        289,
        290,
        291,
        292,
        293,
        294,
        295,
        296,
        297,
        298,
        303,
        304,
        305,
        306,
        307,
        308,
        309,
        310,
        311,
        312,
        313,
        314,
        315,
        316,
        317,
        318,
        323,
        324,
        325,
        326,
        327,
        328,
        329,
        330,
        331,
        332,
        333,
        334,
        335,
        336,
        337,
        338,
        343,
        344,
        345,
        346,
        347,
        348,
        349,
        350,
        351,
        352,
        353,
        354,
        355,
        356,
        357,
        358
      };


      double sml_init[256] = {
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612,
        0.10000000149011612
      };

      double sml_solution[256] = {
        0.06382029866970987,
        0.06382029866970987,
        0.06382029866970935,
        0.0638202986697097,
        0.06382029866970887,
        0.0638202986697091,
        0.06382029866970987,
        0.06382029866970987,
        0.06382029866970935,
        0.0638202986697097,
        0.06382029866970887,
        0.0638202986697091,
        0.06382029866970935,
        0.06382029866970935,
        0.0638202986697107,
        0.0638202986697096,
        0.06382029866970913,
        0.06382029866970954,
        0.0638202986697097,
        0.0638202986697097,
        0.0638202986697096,
        0.06382029866970973,
        0.06382029866970854,
        0.06382029866970887,
        0.06382029866970887,
        0.06382029866970887,
        0.06382029866970913,
        0.06382029866970854,
        0.06382029866970951,
        0.06382029866970954,
        0.0638202986697091,
        0.0638202986697091,
        0.06382029866970954,
        0.06382029866970887,
        0.06382029866970954,
        0.06382029866970984,
        0.08910551922544047,
        0.07347351153030265,
        0.07294831444197504,
        0.07294838558203412,
        0.07294838570123591,
        0.07294831450749978,
        0.07294831450749978,
        0.07294831450749924,
        0.07294831450749996,
        0.07294831450749971,
        0.07294831450749951,
        0.0729483857012358,
        0.0729483855820348,
        0.0729483144419753,
        0.07347351153030357,
        0.08910551922543926,
        0.07347351153030265,
        0.0639626381034397,
        0.06389016612197894,
        0.06389010364584738,
        0.06389016582648527,
        0.0638901037543337,
        0.0638901037543337,
        0.0638901037543337,
        0.0638901037543342,
        0.0638901037543346,
        0.06389010375433346,
        0.06389016582648498,
        0.0638901036458473,
        0.06389016612197941,
        0.06396263810344001,
        0.07347351153030231,
        0.07294831444197504,
        0.06389016612197894,
        0.0638202985375893,
        0.06382029870501933,
        0.06382029811594082,
        0.06382029811594134,
        0.06382029811594134,
        0.06382029811594139,
        0.06382029811594109,
        0.06382029811594069,
        0.06382029811594143,
        0.06382029811594127,
        0.0638202987050199,
        0.06382029853758889,
        0.06389016612197967,
        0.07294831444197536,
        0.07294838558203412,
        0.06389010364584738,
        0.06382029870501933,
        0.0638203604548305,
        0.06382029853873045,
        0.0638202985387304,
        0.0638202985387304,
        0.06382029853873065,
        0.0638202985387304,
        0.06382029853873054,
        0.06382029853873086,
        0.06382029853873047,
        0.06382036045483094,
        0.0638202987050196,
        0.06389010364584802,
        0.07294838558203355,
        0.07294838570123591,
        0.06389016582648527,
        0.06382029811594082,
        0.06382029853873045,
        0.06382029866970881,
        0.06382029866970981,
        0.06382029866970981,
        0.06382029866971003,
        0.06382029866970879,
        0.06382029866970955,
        0.06382029866970941,
        0.06382029866970985,
        0.06382029853873052,
        0.06382029811594168,
        0.06389016582648424,
        0.07294838570123505,
        0.07294831450749978,
        0.0638901037543337,
        0.06382029811594134,
        0.0638202985387304,
        0.06382029866970981,
        0.06382029866970976,
        0.06382029853873086,
        0.06382029811594163,
        0.06389010375433439,
        0.0729483145075002,
        0.07294831450749978,
        0.0638901037543337,
        0.06382029811594134,
        0.0638202985387304,
        0.06382029866970981,
        0.06382029866970976,
        0.06382029853873086,
        0.06382029811594163,
        0.06389010375433439,
        0.0729483145075002,
        0.07294831450749924,
        0.0638901037543337,
        0.06382029811594139,
        0.06382029853873065,
        0.06382029866971003,
        0.06382029866970845,
        0.0638202985387302,
        0.06382029811594106,
        0.06389010375433372,
        0.07294831450749913,
        0.07294831450749996,
        0.0638901037543342,
        0.06382029811594109,
        0.0638202985387304,
        0.06382029866970879,
        0.06382029866971106,
        0.06382029853873046,
        0.06382029811594134,
        0.06389010375433453,
        0.0729483145074994,
        0.07294831450749971,
        0.0638901037543346,
        0.06382029811594069,
        0.06382029853873054,
        0.06382029866970955,
        0.0638202986697091,
        0.06382029853872986,
        0.0638202981159424,
        0.06389010375433353,
        0.07294831450749971,
        0.07294831450749951,
        0.06389010375433346,
        0.06382029811594143,
        0.06382029853873086,
        0.06382029866970941,
        0.06382029866970904,
        0.06382029853873135,
        0.06382029811594075,
        0.06389010375433418,
        0.07294831450749978,
        0.0729483857012358,
        0.06389016582648498,
        0.06382029811594127,
        0.06382029853873047,
        0.06382029866970985,
        0.06382029866970976,
        0.06382029866970976,
        0.06382029866970845,
        0.06382029866971106,
        0.0638202986697091,
        0.06382029866970904,
        0.0638202986697097,
        0.06382029853872999,
        0.06382029811594118,
        0.0638901658264854,
        0.07294838570123603,
        0.0729483855820348,
        0.0638901036458473,
        0.0638202987050199,
        0.06382036045483094,
        0.06382029853873052,
        0.06382029853873086,
        0.06382029853873086,
        0.0638202985387302,
        0.06382029853873046,
        0.06382029853872986,
        0.06382029853873135,
        0.06382029853872999,
        0.0638203604548303,
        0.06382029870501937,
        0.06389010364584731,
        0.07294838558203418,
        0.0729483144419753,
        0.06389016612197941,
        0.06382029853758889,
        0.0638202987050196,
        0.06382029811594168,
        0.06382029811594163,
        0.06382029811594163,
        0.06382029811594106,
        0.06382029811594134,
        0.0638202981159424,
        0.06382029811594075,
        0.06382029811594118,
        0.06382029870501937,
        0.0638202985375891,
        0.063890166121979,
        0.07294831444197432,
        0.07347351153030357,
        0.06396263810344001,
        0.06389016612197967,
        0.06389010364584802,
        0.06389016582648424,
        0.06389010375433439,
        0.06389010375433439,
        0.06389010375433372,
        0.06389010375433453,
        0.06389010375433353,
        0.06389010375433418,
        0.0638901658264854,
        0.06389010364584731,
        0.063890166121979,
        0.06396263810343913,
        0.07347351153030306,
        0.08910551922543926,
        0.07347351153030231,
        0.07294831444197536,
        0.07294838558203355,
        0.07294838570123505,
        0.0729483145075002,
        0.0729483145075002,
        0.07294831450749913,
        0.0729483145074994,
        0.07294831450749971,
        0.07294831450749978,
        0.07294838570123603,
        0.07294838558203418,
        0.07294831444197432,
        0.07347351153030306,
        0.08910551922543915
      };


    }; // end class
  } // namespace oneDim
} // namespace initialConditions
