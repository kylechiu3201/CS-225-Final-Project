#pragma once

#include <algorithm>
#include <queue>
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
    unordered_map<int, long double> distances;
    unordered_map<int, int> parents;
    Graph graph;
  };

  void bfs(Vertex v, vector<Vertex>& path);
  void bfs();


  vector<Airport> shortest_path(std::string B);
  long double shortest_dist(std::string B);
  void create_dijkstras(std::string A);
  void shortest_to_text(std::string B);

  Graph& get_graph();
  vector<Vertex> getVertices();
  vector<Edge> getEdges();

  unordered_map<int, Airport> get_id_map();
  unordered_map<std::string, Airport> get_port_map();

  std::string airlinesAdded(std::string airline);
  std::vector<std::vector<Vertex>> getStronglyConnected(std::string airline);
  std::string exportStronglyConnected(map<Airline, vector<vector<Vertex>>> scc);

 private:
  Graph g_;
  Airport startingPort_;
  std::unordered_map<std::string, Airport> port_map;
  std::unordered_map<int, Airport> id_map;
  std::map<Airline, Graph> lineGraph;
  std::unordered_map<std::string, Airline> air_map;
  std::map<Airline, std::set<std::pair<Vertex, Vertex>>> linetoedges;
  std::vector<Airline> airlines;
  std::map<Vertex, Vertex> vertices;
  vector<Edge> edges;
  dijkstras_graph d_graph;
  void path_helper(int b, vector<Airport>& vec);
  void tarjanHelper(Vertex v, std::map<Vertex, int>& discover,
                              std::map<Vertex, int>& low, std::stack<Vertex>& s,
                              std::map<Vertex, bool>& stackHasNode,
                              std::vector<std::vector<Vertex>>& stronglyConnected, Graph g);
};
