#include "airports.h"

#include <stdlib.h>

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using std::pair;
using std::priority_queue;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

#define INF 0x3f3f3f3f

Airports::Airports() : g_(true, true) {
  // num_airports = 0;
  std::string filename;
  std::cout << "Enter airport data file name:"
            << std::endl;  // read in airport data set
  std::cin >> filename;
  std::ifstream file(filename);
  if (file.fail()) {
    std::cout << "Error opening file. Quitting..." << std::endl;
    exit(EXIT_FAILURE);
    return;
  }
  std::string str, name, city, country, IATA, ICAO;
  int port;
  double latitude, longitude;
  bool first = false;
  while (std::getline(file, str)) {
    std::stringstream ss(
        str);  // takes the line of data and puts them into fields
    string data;
    getline(ss, data, ',');
    port = std::stoi(data);
    getline(ss, data, ',');
    name = data;
    getline(ss, data, ',');
    city = data;
    getline(ss, data, ',');
    country = data;
    getline(ss, data, ',');
    IATA = data;
    getline(ss, data, ',');
    ICAO = data;
    getline(ss, data, ',');
    std::stringstream(data) >> latitude;
    getline(ss, data, ',');
    std::stringstream(data) >> longitude;
    Airport airport_(port, name, city, country, IATA, ICAO, latitude,
                     longitude);
    if (first == false) {
      startingPort_ = airport_;
      first = true;
    }
    g_.insertVertex(airport_);  // insert airports as vertexes
    if (IATA.compare("") != 0 && IATA.compare("\\N") != 0) {
      port_map.insert({IATA, airport_});
    }
    if (ICAO.compare("") != 0 && ICAO.compare("\\N") != 0) {
      port_map.insert({ICAO, airport_});
    }
    id_map[airport_.get_port_ID()] = airport_;
    // num_airports++;
  }
  file.close();

  std::string fileair;
  std::cout << "Enter airline data file name:"
            << std::endl;  // read in route data set
  std::cin >> fileair;
  std::ifstream file_a(fileair);
  int ID;

  while (std::getline(file_a, str)) {
    std::stringstream ss(
        str);  // takes the line of data and puts them into fields
    string data;
    getline(ss, data, ',');
    ID = std::stoi(data);
    getline(ss, data, ',');
    name = data;
    getline(ss, data, ',');
    getline(ss, data, ',');
    IATA = data.substr(1, data.size() - 2);
    getline(ss, data, ',');
    ICAO = data.substr(1, data.size() - 2);
    getline(ss, data, ',');
    getline(ss, data, ',');
    country = data;

    Airline airline_(ID, name, IATA, ICAO, country);
    if (IATA.compare("") != 0 && IATA.compare("\\N") != 0) {
      air_map.insert({IATA, airline_});
    }
    if (ICAO.compare("") != 0 && ICAO.compare("\\N") != 0) {
      air_map.insert({ICAO, airline_});
    }
  }
  file_a.close();
  std::string fileroute;
  std::cout << "Enter route data file name:"
            << std::endl;  // read in route data set
  std::cin >> fileroute;
  std::ifstream file_r(fileroute);
  while (std::getline(file_r, str)) {
    std::stringstream ss(
        str);  // takes the line of data and puts them into fields
    string data, air, source, dest;
    getline(ss, data, ',');
    air = data;
    getline(ss, data, ',');
    getline(ss, data, ',');
    source = data;
    getline(ss, data, ',');
    getline(ss, data, ',');
    dest = data;
    g_.insertEdge(port_map[source], port_map[dest], air_map[air]);
    g_.setEdgeWeight(port_map[source], port_map[dest],
                     Airport::get_distance(port_map[source], port_map[dest]));
  }
  file_r.close();
}
void Airports::bfs() {}

void Airports::path_helper(int b, vector<string>& vec) {
  if (d_graph.parents[b] == -1) {
    return;
  }
  vec.insert(vec.begin(), id_map[d_graph.parents[b]].get_name());
  path_helper(d_graph.parents[b], vec);
}

vector<std::string> Airports::shortest_path(
    Airport b) {  // currently returns name of each airport
  int dest = b.get_port_ID();
  vector<string> shortest;
  path_helper(dest, shortest);
  shortest.push_back(b.get_name());
  return shortest;
}

int Airports::shortest_dist(Airport b) {
  return d_graph.distances[b.get_port_ID()];
}

Airports::djikstras_graph Airports::create_djikstras(Airport a) {
  // cin somewhere and set starting airport
  // also figure out what to return::: shortest distance between two airports +
  // path to get there?
  int start_id = a.get_port_ID();
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 std::greater<pair<int, int>>>
      pq;  // first int is distance, second int is vertex/port_id
  unordered_map<int, int> parent;  // first is port_id, second is parent port_id
  unordered_map<int, int> distance;  // first is port_id, second is distance
  unordered_set<int> visited;

  vector<Vertex> vertices = g_.getVertices();
  for (auto v : vertices) {
    distance[v.get_port_ID()] = INF;
    parent[v.get_port_ID()] = -1;  // port id = -1 for default
  }
  distance[start_id] = 0;
  // handle starting airport
  pair<int, int> airport_id = std::make_pair(start_id, 0);
  pq.push(airport_id);

  while (!pq.empty()) {
    int u = pq.top().second;  // current airport id
    pq.pop();
    visited.insert(u);

    d_graph.graph.insertVertex(id_map[u]);
    vector<Vertex> vert = g_.getAdjacent(id_map[u]);
    for (int x = 0; x < (int)vert.size(); x++) {
      int v = vert[x].get_port_ID();  // child airport_id
      int weight = g_.getEdgeWeight(id_map[u], vert[x]);

      // if vertex we are going to hasn't been processed yet  &&
      if (visited.find(v) == visited.end() &&
          distance[v] > distance[u] + weight) {
        distance[v] = distance[u] + weight;
        pq.push(std::make_pair(distance[v], v));
        parent[v] = u;
      }
    }
  }
  d_graph.distances = distance;
  d_graph.parents = parent;
}

std::vector<Vertex> Airports::getStronglyConnected() {
  auto vertices = g_.getVertices();
  std::map<Vertex, int> discover;
  std::map<Vertex, int> low;
  std::map<Vertex, bool> stackHasNode;
  std::stack<Vertex> s;
  std::vector<Vertex> stronglyConnected;

  for (auto v : vertices) {
    discover[v] = -1;
    low[v] = -1;
    stackHasNode[v] = false;
  }

  for (auto v : vertices)
    if (discover[v] == -1)
      tarjanHelper(v, discover, low, s, stackHasNode, stronglyConnected);

  return stronglyConnected;
}

void Airports::tarjanHelper(Vertex v, std::map<Vertex, int>& discover,
                            std::map<Vertex, int>& low, std::stack<Vertex>& s,
                            std::map<Vertex, bool>& stackHasNode,
                            std::vector<Vertex>& stronglyConnected) {
  static int time = 0;
  ++time;
  discover[v] = time;
  low[v] = time;
  s.push(v);
  stackHasNode[v] = true;
  auto adjacent = g_.getAdjacent(v);

  for (auto adj : adjacent) {
    if (discover[adj] == -1) {
      tarjanHelper(adj, discover, low, s, stackHasNode, stronglyConnected);
      low[v] = std::min(low[v], low[adj]);
    } else if (stackHasNode[adj] == true)
      low[v] = std::min(low[v], discover[adj]);
  }

  Vertex temp;
  if (low[v] == discover[v]) {
    while (!s.empty() && s.top() != v) {
      temp = s.top();
      stronglyConnected.push_back(temp);
      stackHasNode[temp] = false;
      s.pop();
    }
    if (!s.empty()) {
      temp = s.top();
      stronglyConnected.push_back(temp);
      stackHasNode[temp] = false;
      s.pop();
    }
  }
}
