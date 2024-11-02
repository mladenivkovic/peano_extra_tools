#pragma once

#include <string>
#include <vector>

namespace initialConditions {

  struct InitialConditions {

    std::string name;
    int sampleSize;
    int indexBegin;
    int indexEnd;

    double h_tolerance;
    double resolution_eta;

    double h_min;
    double h_max;

    std::vector<std::vector<double>> coords;

    std::vector<int> ids;

    std::vector<double> sml_init;

    std::vector<double> sml_solution;

  };
} // namespace initialConditions
