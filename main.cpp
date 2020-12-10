#include <iostream>

#include "airports/airports.h"

int main() {
  // gets airport data
  std::string filename;
  std::cout << "Enter airport data file name:"
            << std::endl;  // read in airport data set
  std::cin >> filename;

  // gets airline data
  std::string fileair;
  std::cout << "Enter airline data file name:"
            << std::endl;  // read in route data set
  std::cin >> fileair;

  // gets route data
  std::string fileroute;
  std::cout << "Enter route data file name:"
            << std::endl;  // read in route data set
  std::cin >> fileroute;
  std::cout << "Creating graph...\n";

  Airports airports(filename, fileair, fileroute);

  std::string command;
  bool done = false;
  while (!done) {
    std::cout
        << "\nChoose a command: getDist, airlineNeeded, allNeeded, bfs, exit\n";
    std::cin >> command;

    // if(command == "getDist")
    //   airports.shortest_path();
    
    if (command == "allNeeded") {
      std::string filename = airports.airlinesAdded("allAirlines");
      if(filename == "empty")
        std::cout << "\nNo airports needed to be added for any airlines.\n\n";
      else
        std::cout << "\nData exported to \"" << filename << "\".\n\n";
    } 

    else if (command == "airlineNeeded") {
      std::cout << "Which airline? Use IATA or ICAO\n";
      std::string airline;
      std::cin >> airline;
      std::string filename = airports.airlinesAdded("\"" + airline + "\"");
      if(filename == "empty")
        std::cout << "\nNo airports needed to be added for the selected airline.\n\n";
      else
        std::cout << "\nData exported to \"" << filename << "\".\n\n";
    } 

    else if (command == "bfs")
      airports.bfs();

    else if (command == "exit")
      done = true;

    else
      std::cout << "'" << command << "' is not a recognized command.\n";
  }
  return 0;
}
