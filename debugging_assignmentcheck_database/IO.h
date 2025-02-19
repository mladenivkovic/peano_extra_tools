#include <iostream> // IO library
#include <string>   // strings
#include <vector>
#include <sstream>
#include <fstream>

#include "tarch/la/Vector.h"


namespace io {

  namespace internal {
    /**
     * Split a line between commas.
     */
    std::vector<std::string> splitline_comma(std::string line){

      std::vector<std::string> parts = {};
      size_t index_start = 0;
      int open_parentheses = 0;
      int open_brackets = 0;

      for (size_t i = 0; i < line.length(); i++){

        if ((line[i] == ',') and (open_parentheses == 0) and (open_brackets == 0)) {
          // Found split.
          // second arg is length, not position
          std::string part = line.substr(index_start, i-index_start);
          parts.push_back(part);
          index_start = i+1;
        }
        else if (line[i] == ')'){
          open_parentheses--;
        }
        else if (line[i] == '('){
          open_parentheses++;
        }
        else if (line[i] == ']'){
          open_brackets--;
          std::cout << "========================================== FOUND BRACKET CLOSE\n";
        }
        else if (line[i] == '['){
          open_brackets++;
          std::cout << "========================================== FOUND BRACKET OPEN\n";
        }

        if (open_parentheses < 0) {
          std::cerr << "Negative open parentheses? index=" << i << "Line:\n" << line << std::endl;
          std::abort();
        }
        if (open_brackets < 0) {
          std::cerr << "Negative open brackets? index=" << i << "Line:\n" << line << std::endl;
          std::abort();
        }
      }

      if (index_start < line.length()) {
        parts.push_back(line.substr(index_start));
      }

      return parts;
    }

    /**
     * Extract a vector from a string it got printed as.
     */
    tarch::la::Vector<Dimensions, double> getVector(std::string vectorString) {

      tarch::la::Vector<Dimensions, double> result;


      if (Dimensions == 1) {
        std::cerr << "Not implemented for 1D" << std::endl;
        std::abort();
      }
      else if (Dimensions == 2) {

        double v1, v2;

        if (std::sscanf(vectorString.c_str(), "[%lf,%lf]", &v1, &v2) == 2) {
            std::cout << v1 << "," << v2 << std::endl;
        } else {
            std::cerr << "Invalid format" << std::endl;
            std::cerr << vectorString << std::endl;
            std::abort();
        }

        // std::istringstream stream(vectorString);
        // std::string leftBracket, comma, rightBracket;
    /*     stream >> leftBracket >> v1 >> comma >> v2 >> rightBracket; */
        /* if (leftBracket != "[") { */
        /*   std::cerr << "Error in vector partsing: Left bracket not correct\n"; */
        /*   std::cerr << ">>> Left bracket:" << leftBracket << "\n"; */
        /*   std::cerr << ">>> VectorString:" << vectorString << std::endl; */
        /*   std::abort(); */
        /* } */
        /* if (rightBracket != "]") { */
        /*   std::cerr << "Error in vector partsing: Right bracket not correct\n"; */
        /*   std::cerr << ">>> Right bracket:" << rightBracket << "\n"; */
        /*   std::cerr << ">>> VectorString:" << vectorString << std::endl; */
        /*   std::abort(); */
        /* } */
        /* if (comma != ",") { */
        /*   std::cerr << "Error in vector partsing: Comma not correct\n"; */
        /*   std::cerr << ">>> comma:" << comma << "\n"; */
        /*   std::cerr << ">>> VectorString:" << vectorString << std::endl; */
        /*   std::abort(); */
        /* } */
/*  */
        // result(0) = v1;
        // result(1) = v2;

      }
      else if (Dimensions == 3) {
        std::cerr << "Not implemented for 3D" << std::endl;
        std::abort();
      }


      return result;
    }


    /**
     * "Convert" string to bool.
     * Return true if s == "true", false if s == "false",
     * or throw error otherwise
     */
    bool stobool(std::string s) {
      if ((s == "true") or (s == "1")) {
        return true;
      }
      if ((s == "false") or (s == "0")) {
        return false;
      }

      std::cerr << "Error converting string to bool: str=" << s << std::endl;
      std::abort();
    }

  } // namespace internal

  /**
   * Read in trace file
   *
   * @param filename: Which file to read in
   * @param filter: Keep lines that start with that string only
   */
  std::vector<std::vector<std::string>> read_trace_file(std::string filename, std::string filter) {

    std::vector<std::vector<std::string>> tracelines;

    std::string line;
    std::ifstream  tracefile(filename);
    while (std::getline(tracefile, line)) {

      if (not line.starts_with(filter)) {
        continue;
      }

      std::string trimmed = line.substr(filter.length());
      std::vector<std::string> splits = internal::splitline_comma(trimmed);

      // std::cout << "LINE:" << line << "\n" << "TRIMMED:" << trimmed << "\n";
      // for (auto s: splits) std::cout << ">>> " << s << "\n";
      // std::cout << std::endl;

      tracelines.push_back(splits);
    }

    tracefile.close();

    return tracelines;
  }


} // namespace io
