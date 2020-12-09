#pragma once
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../airline/airline.h"
#include "../airport/airport.h"
#include "../graph/edge.h"
#include "../graph/graph.h"

using std::string;
using std::unordered_map;
class Airports {
 public:
  Airports(std::string filename, std::string fileair, std::string fileroute);

  struct dijkstras_graph {
    dijkstras_graph() : graph(true, true){};
    unordered_map<int, int> distances;
    unordered_map<int, int> parents;
    Graph graph;
  };

  void bfs();
  std::vector<Vertex> getStronglyConnected(std::string airline);

  vector<std::string> shortest_path(Airport b);
  int shortest_dist(Airport b);
  void create_dijkstras(Airport a);


  Graph & get_graph();
  vector<Vertex> getVertices();
  vector<Edge> getEdges();

  unordered_map<int, Airport> get_id_map();


 private:
  Graph g_;
  Airport startingPort_;
  // int num_airports;
  std::unordered_map<std::string, Airport> port_map;
  std::unordered_map<int, Airport> id_map;
  std::map<Airline, Graph> lineGraph;
  std::unordered_map<std::string, Airline> air_map;
  std::map<Airline, std::set<std::pair<Vertex, Vertex>>> linetoedges;
  /* std::map<std::pair<Vertex, Vertex>, std::set<Airline>> airlineEdges; */

  dijkstras_graph d_graph;
  void path_helper(int b, vector<string>& vec);

  /* void tarjanHelper(Vertex v, std::map<Vertex, int>& discover, */
  /*                   std::map<Vertex, int>& low, std::stack<Vertex>& s, */
  /*                   std::map<Vertex, bool>& stackHasNode, */
  /*                   std::vector<Vertex>& stronglyConnected, std::map<Vertex, vector<Vertex>>& edges); */
  void tarjanHelper(Vertex v, std::map<Vertex, int>& discover,
                    std::map<Vertex, int>& low, std::stack<Vertex>& s,
                    std::map<Vertex, bool>& stackHasNode,
                    std::vector<Vertex>& stronglyConnected, Graph g);
};
