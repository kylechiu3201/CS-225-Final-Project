#include <iostream>
#include "airports/airports.h"

int main() {
  Airports airports;
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
