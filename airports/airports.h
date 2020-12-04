#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

#include "../airport/airport.h"
#include "../graph/edge.h"
#include "../graph/graph.h"
#include "../airline/airline.h"

using std::string;

class Airports {
 public:
  Airports();
  void bfs();
  void getStronglyConnected();
  void shortest_path(Airport a, Airport b);

 private:
  Graph g_;
  Airport startingPort_;
  std::unordered_map<std::string, Airline> air_map;
  std::unordered_map<std::string, Airport> port_map;
};
