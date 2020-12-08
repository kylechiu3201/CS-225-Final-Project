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
using std::unordered_map;
class Airports {
 public:
  Airports();

 struct djikstras_graph {
    djikstras_graph() : graph(true,true){};
    unordered_map<int,int> distances;
    unordered_map<int,int> parents;
    Graph graph;
  };

  
  void bfs();
  void getStronglyConnected();

  void path_helper(int b, vector<string> & vec);
  vector<std::string> shortest_path(Airport b);
  int shortest_dist(Airport b);
  djikstras_graph create_djikstras(Airport a);

 private:
  Graph g_;
  Airport startingPort_;
  //int num_airports;
  std::unordered_map<std::string, Airline> air_map;
  std::unordered_map<std::string, Airport> port_map;
  std::unordered_map<int, Airport> id_map;
  

  djikstras_graph d_graph;


  
};
