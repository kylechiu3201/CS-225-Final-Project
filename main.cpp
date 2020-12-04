#include <iostream>
#include "airport.h"
#include "airports.h"

int main() {
  std::cout << "Enter filename of airport data: \n";
  std::string filename;
  std::cin >> filename;
  std::cout << std::endl;
  Airports airports(filename);
  std::string command;
  bool done = false;
  while(!done) {
    std::cout << "Choose a command: getDist, neededAirlines, bfs, exit\n";
    std::cin >> command;
    if(command == "getDist") {
      std::string airport1, airport2;
      std::cout << "\nEnter starting airport: \n";
      std::cin >> airport1;
      std::cout << "\nEnter destination airport: \n";
      std::cin >> airport2;
      std::cout << "\n\n\n";
      airports.getDistance(airport1, airport2);
      std::cout << "\n\n\n";
    }
    else if(command == "neededAirlines") {
      std::string airline;
      std::cout << "\nEnter airline: \n";
      std::cin >> airline;
      std::cout << "\n\n\n";
      airports.getStronglyConnected(airline);
      std::cout << "\n\n\n";
    }
    else if(command == "bfs") {
      std::cout << "\n\n\n";
      airports.bfs();
      std::cout << "\n\n\n";
    }
    else if(command == "exit")
      done = true;
    else
      std::cout << "'" << command << "' is not a recognized command.\n\n";
  }
  return 0;
}
