#include <vector>
#include "IO.h"

#include "toolbox/particles/assignmentchecks/Database.h"
#include "toolbox/particles/assignmentchecks/TracingAPI.h"
#include "tarch/la/Vector.h"


/**
 * Run tests for collected trace of DATABASE calls.
 */
void test_database_trace(){

  // read file
  std::vector<std::vector<std::string>> tracelines = io::read_trace_file("tracefile2.dat", "DATABASE_TRACE:");

  for (auto line: tracelines) {

    std::string call = line[0];

    if (call == "addEvent"){
      std::cout << "Got addEvent\n";
    }
    else if (call == "toString"){
      std::cout << "Got toString\n";
    }
    else if (call == "startMeshSweep"){
      std::cout << "Got startMeshSweep\n";
    }
    else if (call == "shiftIdentifierCoordinates"){
      std::cout << "Got shiftIdentifierCoordinates\n";
    }
    else if (call == "replaceEvent"){
      std::cout << "Got replaceEvent\n";
    }
    else if (call == "reset"){
      std::cout << "Got reset\n";
    }

    else {
      std::cout << "Unknown call -" << call << std::endl;
      std::abort();
    }

  }
}



/**
 * Run tests for collected trace of TRACING calls.
 */
void test_tracingapi_trace(){

  // read file
  std::vector<std::vector<std::string>> tracelines = io::read_trace_file("tracefile2.dat", "TRACE:");

  for (auto line: tracelines) {

    std::string call = line[0];

    if (call == "assignParticleToVertex"){

      assertion1(line.size() == 11, line);

      // std::cout << "Got assignParticleToVertex\n";
      std::string particleName = line[1];
      tarch::la::Vector<Dimensions, double> particleX = io::internal::getVector(line[2]);
      int particleID = std::stoi(line[3]);
      bool isLocal = io::internal::stobool(line[4]);
      tarch::la::Vector<Dimensions, double> vertexX = io::internal::getVector(line[5]);
      tarch::la::Vector<Dimensions, double> vertexH = io::internal::getVector(line[6]);
      int treeId = std::stoi(line[7]);
      std::string trace = line[8];
      bool particleIsNew = io::internal::stobool(line[9]);
      bool reassignmentOnSameTreeDepthAllowed = io::internal::stobool(line[10]);
      // toolbox::particles::assignmentchecks::assignParticleToVertex(
      // particleName, particleX, particleID, isLocal, vertexX, vertexH, treeId, trace, particleIsNew, reassignmentOnSameTreeDepthAllowed );
    }
    else if (call == "detachParticleFromVertex"){

      assertion1(line.size() == 9, line);

      // std::cout << "Got detachParticleFromVertex\n";
      std::string particleName = line[1];
      tarch::la::Vector<Dimensions, double> particleX = io::internal::getVector(line[2]);
      std::cout << "line[3]:" <<  line[3] << std::endl;
      std::cout << "line:" << std::endl;
      for (auto l: line) {
        std::cout << ">>> " << l << "\n";
      }
      std::cout << std::endl;
      int particleID = std::stoi(line[3]);
      bool isLocal = io::internal::stobool(line[4]);
      tarch::la::Vector<Dimensions, double> vertexX = io::internal::getVector(line[5]);
      tarch::la::Vector<Dimensions, double> vertexH = io::internal::getVector(line[6]);
      int treeId = std::stoi(line[7]);
      std::string trace = line[8];
      // toolbox::particles::assignmentchecks::assignParticleToVertex(
      // particleName, particleX, particleID, isLocal, vertexX, vertexH, treeId, trace, particleIsNew, reassignmentOnSameTreeDepthAllowed );
    }
    else if (call == "startMeshSweep"){

      assertion1(line.size() == 2, line);

      std::cout << "Got startMeshSweep\n";
      std::string meshSweepName = line[1];
      // toolbox::particles::assignmentchecks::startMeshSweep(meshSweepName);
    }
    else if (call == "eraseParticle"){

      assertion1(line.size() == 8, line);

      // std::cout << "Got eraseParticle\n";
      std::string particleName = line[1];
      tarch::la::Vector<Dimensions, double> particleX = io::internal::getVector(line[2]);
      int particleID = std::stoi(line[3]);
      bool isLocal = io::internal::stobool(line[4]);
      tarch::la::Vector<Dimensions, double> vertexH = io::internal::getVector(line[5]);
      int treeId = std::stoi(line[6]);
      std::string trace = line[7];
      // toolbox::particles::assignmentchecks::eraseParticle(
      // particleName, particleX, particleID, isLocal, vertexH, treeId, trace );
    }
    else if (call == "moveParticle"){

      assertion1(line.size() == 9, line);

      // std::cout << "Got moveParticle\n";
      std::string particleName = line[1];
      tarch::la::Vector<Dimensions, double> oldParticleX = io::internal::getVector(line[2]);
      tarch::la::Vector<Dimensions, double> newParticleX = io::internal::getVector(line[3]);
      int particleID = std::stoi(line[4]);
      tarch::la::Vector<Dimensions, double> vertexX = io::internal::getVector(line[5]);
      tarch::la::Vector<Dimensions, double> vertexH = io::internal::getVector(line[6]);
      int treeId = std::stoi(line[7]);
      std::string trace = line[8];
      // toolbox::particles::assignmentchecks::moveParticle(
      // particleName, oldParticleX, newParticleX, particleID, vertexX, vertexH, treeId, trace);
    }
    else if (call == "assignParticleToSieveSet"){

      assertion1(line.size() == 8, line);

      // std::cout << "Got assignParticleToSieveSet\n";
      std::string particleName = line[1];
      tarch::la::Vector<Dimensions, double> particleX = io::internal::getVector(line[2]);
      int particleID = std::stoi(line[3]);
      bool isLocal = io::internal::stobool(line[4]);
      tarch::la::Vector<Dimensions, double> vertexH = io::internal::getVector(line[5]);
      int treeId = std::stoi(line[6]);
      std::string trace = line[7];
      // toolbox::particles::assignmentchecks::assignParticleToVertex(
    }
    else if (call == "reset"){
      std::cout << "Got reset\n";
    }

    else {
      std::cout << "Unknown call:" << call << std::endl;
      std::abort();
    }

  }

}


int main() {

  // get database
  // auto& db = toolbox::particles::assignmentchecks::internal::Database::getInstance();

  // test_database_trace();
  test_tracingapi_trace();

  return 0;
}
