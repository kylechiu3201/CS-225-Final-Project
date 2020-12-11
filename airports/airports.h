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

/**
 * @brief Airports class with graph algorithms for the graph of the airport and
 * route data
 */
class Airports {
 public:
  /**
   * @brief Creates an Airports object with the given parameters
   *
   * @param filename The path of the file for airport data
   * @param fileair The path of the file for airline data
   * @param fileroute The path of the file for route data
   */
  Airports(std::string filename, std::string fileair, std::string fileroute);

  /**
   * @brief Helper function for bfs()
   *
   * @param v The current Vertex
   * @param path The path of the search
   */
  void bfs(Vertex v, vector<Vertex>& path);

  /**
   * @brief Performs a breadth first search on the Airport graph
   *
   * @return The vector of the breadth first search
   */
  vector<vector<Vertex>> bfs();

  /**
   * @brief Exports the breadth first search to a text file
   *
   * @param v The breadth first search vector
   */
  void bfs_to_text(vector<vector<Vertex>> v);

  /**
   * @brief Gets the shortest path from one airport to another
   *
   * @param B The name of the airport
   *
   * @return The vector of the vertices in the path
   */
  vector<Airport> shortest_path(std::string B);

  /**
   * @brief Gets the shortest distance from one airport to another
   *
   * @param B The name of the airport
   *
   * @return The distance from one airport to another
   */
  long double shortest_dist(std::string B);

  /**
   * @brief Sets up Dijkstra's algorithm
   *
   * @param A The name of the starting airport
   *
   * @return The vector of the airport IDs
   */
  vector<int> create_dijkstras(std::string A);

  /**
   * @brief Exports the shortest path data to a text file
   *
   * @param B The name of the airport
   */
  void shortest_to_text(std::string B);

  /**
   * @brief Gets the current airport graph
   *
   * @return The current airport graph
   */
  Graph& get_graph();

  /**
   * @brief Gets all vertices in the airport graph
   *
   * @return The vector of all vertices in the airport graph
   */
  vector<Vertex> getVertices();

  /**
   * @brief Gets all edges in the airport graph
   *
   * @return The vector of all edges in the airport graph
   */
  vector<Edge> getEdges();

  /**
   * @brief Gets the map from IDs to Airport objects
   *
   * @return The map from IDs to Airport objects
   */
  unordered_map<int, Airport> get_id_map();

  /**
   * @brief Gets the map from IATA/ICAO to Airport objects
   *
   * @return The map from IATA/ICAO to Airport objects
   */
  unordered_map<std::string, Airport> get_port_map();

  /**
   * @brief Gets a chosen/all airlines for strongly connected components with an
   * in-degree of zero
   *
   * @param airline Either the IATA/ICAO of the chosen airline or an string that
   * indicates that the user wants all airlines
   *
   * @return The name of the file with the exported data
   */
  std::string airlinesAdded(std::string airline);

  /**
   * @brief Gets the strongly connected components with an in-degree of zero of
   * the given airline
   *
   * @param airline The IATA/ICAO of the chosen airline
   *
   * @return The vector of the strongly connected components with an in-degree
   * of zero
   */
  std::vector<std::vector<Vertex>> getStronglyConnected(std::string airline);

  /**
   * @brief Exports the strongly connected data to a text file
   *
   * @param scc A map of Airlines to its respective vector of strongly connected
   * components
   *
   * @return The name of the file with the exported data
   */
  std::string exportStronglyConnected(map<Airline, vector<vector<Vertex>>> scc);

  struct dijkstras_graph {
    dijkstras_graph() : graph(true, true){};
    unordered_map<int, long double> distances;
    unordered_map<int, int> parents;
    Graph graph;
  };

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

  /**
   * @brief Helper for finding shortest path
   *
   * @param b The port ID of the destination
   * @param vec The vector of Airports in the path
   */
  void path_helper(int b, vector<Airport>& vec);

  /**
   * @brief Helper function for Tarjan's algorithm
   *
   * @param v The current Vertex
   * @param discover The discovered map
   * @param low The low map
   * @param s The stack of Vertices
   * @param stackHasNode The map of if the Vertex is on the stack
   * @param stronglyConnected The vector of the strongly connected components
   * @param g The graph to perform Tarjan's algorithm on
   */
  void tarjanHelper(Vertex v, std::map<Vertex, int>& discover,
                    std::map<Vertex, int>& low, std::stack<Vertex>& s,
                    std::map<Vertex, bool>& stackHasNode,
                    std::vector<std::vector<Vertex>>& stronglyConnected,
                    Graph g);
};
