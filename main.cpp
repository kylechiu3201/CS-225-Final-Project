#include <iostream>
#include "airports/airports.h"

int main() {
  //gets airport data
  std::string filename;
  std::cout << "Enter airport data file name:"
            << std::endl;  // read in airport data set
  std::cin >> filename;

  //gets airline data
  std::string fileair;
  std::cout << "Enter airline data file name:"
            << std::endl;  // read in route data set
  std::cin >> fileair;

  //gets route data
  std::string fileroute;
  std::cout << "Enter route data file name:"
            << std::endl;  // read in route data set
  std::cin >> fileroute;

  Airports airports(filename, fileair, fileroute);
  std::string command;
  bool done = false;
  while(!done) {
    std::cout << "\nChoose a command: getDist, airlinesNeeded, bfs, exit\n";
    std::cin >> command;
    // if(command == "getDist")
    //   airports.shortest_path();
    if(command == "airlinesNeeded")
      airports.getStronglyConnected();
    else if(command == "bfs")
      airports.bfs();
    else if(command == "exit")
      done = true;
    else
      std::cout << "'" << command << "' is not a recognized command.\n";
  }
  return 0;
}
