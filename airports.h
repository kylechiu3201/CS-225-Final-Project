#pragma once
#include <algorithm>
#include <string>
#include <vector>

#include "airport.h"
#include "edge.h"
#include "graph.h"

using std::string;

class Airports {
 public:
  Airports(string file);
  void bfs();
  void getDistance(string airport1, string airport2);
  void getStronglyConnected(string airline);

 private:
  Graph g_;
  Airport startingPort_;
};
