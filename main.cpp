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
    std::cout << "\nChoose a command: getDist, airlineNeeded, allNeeded, bfs, exit\n";
    std::cin >> command;
    // if(command == "getDist")
    //   airports.shortest_path();
    if(command == "allNeeded") {
      auto airlines = airports.airlinesAdded();
      for(auto i : airlines) {
        std::cout << i.first.get_name() << ":   ";
        for(unsigned j = 0; j < i.second.size(); ++j) {
          std::string name = i.second[j].get_IATA();
          if(name == "" || name == "\"\"" || name == "\\N")
            name = i.second[j].get_ICAO();
          if(name == "" || name == "\"\"" || name == "\\N")
            continue;
          std::cout << i.second[j] << std::endl;
          if(j != i.second.size()-1)
            std::cout << ", ";
        }
        std::cout << std::endl << std::endl << std::endl;
      }
    }
    else if(command == "airlineNeeded") {
      std::cout << "Which airline? Use IATA or ICAO\n";
      std::string airline;
      std::cin >> airline;
      vector<Vertex> ans = airports.getStronglyConnected("\"" + airline + "\"");
      if(ans.empty())
        std::cout << "No airports needed to add.";
      else {
        for(unsigned i = 0; i < ans.size(); ++i) {
          std::string name = ans[i].get_IATA();
          if(name == "" || name == "\"\"" || name == "\\N")
            name = ans[i].get_ICAO();
          if(name == "" || name == "\"\"" || name == "\\N")
            continue;
          std::cout << ans[i] << std::endl;
          if(i != ans.size()-1)
            std::cout << ", ";
        }
      }
    }
    else if(command == "bfs")
      airports.bfs();
    else if(command == "exit")
      done = true;
    else
      std::cout << "'" << command << "' is not a recognized command.\n";
  }
  return 0;
}
