#include "airports/airports.h"

int main() {
  Airports airports("data/testairports.dat", "data/testairlines.dat", "data/testroutes.dat");
  std::string command;
  bool done = false;
  while(!done) {
    std::cout << "\nChoose a command: getDist, airlinesNeeded, bfs, exit\n";
    std::cin >> command;
    // if(command == "getDist")
    //   airports.shortest_path();
    if(command == "airlinesNeeded") {
      auto scc = airports.getStronglyConnected("\"DA\"");
      for(auto i : scc)
        std::cout << i.get_port_ID() << " ";
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
