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
  Airports();
  void bfs();
  void getDistance();
  void getStronglyConnected();

 private:
  Graph g_;
  Airport startingPort_;
};
