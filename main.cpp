#include <iostream>

#include "airports/airports.h"

int main() {
  // gets airport data
  std::string filename;
  std::cout << "Enter airport data file name:"
            << std::endl;  // read in airport data set
  std::cin >> filename;
  std::ifstream file(filename);
  if (file.fail()) {
    std::cout << "Error opening file '" << filename << "'. Quitting..."
              << std::endl;
    exit(EXIT_FAILURE);
    return 0;
  }
  file.close();

  // gets airline data
  std::string fileair;
  std::cout << "Enter airline data file name:"
            << std::endl;  // read in route data set
  std::cin >> fileair;
  std::ifstream file_a(fileair);
  if (file_a.fail()) {
    std::cout << "Error opening file '" << fileair << "'. Quitting..."
              << std::endl;
    exit(EXIT_FAILURE);
    return 0;
  }
  file_a.close();

  // gets route data
  std::string fileroute;
  std::cout << "Enter route data file name:"
            << std::endl;  // read in route data set
  std::cin >> fileroute;
  std::ifstream file_r(fileroute);
  if (file_r.fail()) {
    std::cout << "Error opening file '" << fileroute << "'. Quitting..."
              << std::endl;
    exit(EXIT_FAILURE);
    return 0;
  }
  file_r.close();
  std::cout << "Creating graph...\n";

  Airports airports(filename, fileair, fileroute);

  std::string command;
  bool done = false;
  while (!done) {
    std::cout << "\nChoose a command: shortestDist, airlineNeeded, allNeeded, "
                 "bfs, exit\n";
    std::cin >> command;

    if (command == "allNeeded") {
      std::string filename = airports.airlinesAdded("allAirlines");
      if (filename == "empty")
        std::cout << "\nNo airports needed to be added for any airlines.\n\n";
      else
        std::cout << "\nData exported to \"" << filename << "\".\n\n";
    }

    else if (command == "airlineNeeded") {
      std::cout << "Which airline? Use IATA or ICAO\n";
      std::string airline;
      std::cin >> airline;
      std::string filename = airports.airlinesAdded("\"" + airline + "\"");
      if (filename == "empty")
        std::cout
            << "\nNo airports needed to be added for the selected airline.\n\n";
      else
        std::cout << "\nData exported to \"" << filename << "\".\n\n";
    } else if (command == "shortestDist") {
      std::cout << "Enter starting airport IATA/ICAO code";
      std::cout << std::endl;
      std::string A;
      std::cin >> A;
      A = "\"" + A + "\"";
      // std::cout << A;
      unordered_map<std::string, Airport> p_map = airports.get_port_map();
      if (p_map.find(A) == p_map.end()) {
        std::cout << "Please enter valid IATA/ICAO code for starting airport"
                  << std::endl;

      } else {
        airports.create_dijkstras(A);
        bool flag = true;
        while (flag) {
          std::cout << "Enter destination airport IATA/ICAO code. ";
          std::cout << "Enter 'back' to go back.";
          std::cout << std::endl;
          std::string dest;
          std::cin >> dest;

          if (dest == "back") {
            break;
          } else {
            dest = "\"" + dest + "\"";
            // std::cout << dest;
            if (p_map.find(dest) == p_map.end()) {
              std::cout << "Please enter valid IATA/ICAO code for destination "
                           "airport";
            }
            airports.shortest_to_text(dest);
          }
        }
      }

    }

    else if (command == "bfs"){
      vector<vector<Vertex>> b = airports.bfs();
      for(unsigned x = 0; x < b.size(); x++){
    std::cout << "BFS " << x+1 << ":" << std::endl;
    for(unsigned y = 0; y < b[x].size(); y++){
      std::cout << b[x][y] << std::endl;
    }
    std::cout << std::endl;
  }
      airports.bfs_to_text(b);
    }

    else if (command == "exit")
      done = true;

    else
      std::cout << "'" << command << "' is not a recognized command.\n";
  }
  return 0;
}
