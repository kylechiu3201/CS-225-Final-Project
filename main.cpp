#include <iostream>
#include "airports/airports.h"

int main() {
  Airports airports;
  std::cout << std::endl;
  std::string command;
  bool done = false;
  while(!done) {
    std::cout << "Choose a command: getDist, airlinesNeeded, bfs, exit\n";
    std::cin >> command;
    if(command == "getDist")
      airports.getDistance();
    else if(command == "airlinesNeeded")
      airports.getStronglyConnected();
    else if(command == "bfs")
      airports.bfs();
    else if(command == "exit")
      done = true;
    else
      std::cout << "'" << command << "' is not a recognized command.\n\n";
  }
  return 0;
}
