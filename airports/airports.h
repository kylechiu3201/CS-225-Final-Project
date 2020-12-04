#pragma once
#include <algorithm>
#include <string>
#include <vector>

#include "../airport/airport.h"
#include "../graph/edge.h"
#include "../graph/graph.h"

using std::string;

class Airports {
 public:
  Airports();
  void bfs();
  void getDistance();
  void getStronglyConnected();

 private:
  Graph g_;
  Airport startingPort_;
};
