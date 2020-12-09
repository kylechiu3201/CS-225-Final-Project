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

Airports::Airports(std::string filename, std::string fileair, std::string fileroute) : g_(true, true) {
  // num_airports = 0;
  std::ifstream file(filename);
  if (file.fail()) {
    std::cout << "Error opening file '" << filename << "'. Quitting..." << std::endl;
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

  std::ifstream file_a(fileair);
  if (file_a.fail()) {
    std::cout << "Error opening file '" << fileair << "'. Quitting..." << std::endl;
    exit(EXIT_FAILURE);
    return;
  }
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
    /* IATA = data.substr(1, data.size() - 2); */
    IATA = data;
    getline(ss, data, ',');
    /* ICAO = data.substr(1, data.size() - 2); */
    ICAO = data;
    getline(ss, data, ',');
    getline(ss, data, ',');
    country = data;

    Airline airline_(ID, name, IATA, ICAO, country);
    airlines.push_back(airline_);
    if (IATA.compare("") != 0 && IATA.compare("\\N") != 0 && IATA != "\"\"") {
      air_map[IATA] = airline_;
    }
    if (ICAO.compare("") != 0 && ICAO.compare("\\N") != 0 && ICAO != "\"\"") {
      air_map[ICAO] = airline_;
    }
  }
  file_a.close();
  std::ifstream file_r(fileroute);
  if (file_r.fail()) {
    std::cout << "Error opening file '" << fileroute << "'. Quitting..." << std::endl;
    exit(EXIT_FAILURE);
    return;
  }
  while (std::getline(file_r, str)) {
    std::stringstream ss(
        str);  // takes the line of data and puts them into fields
    string data, air, source, dest;
    getline(ss, data, ',');
    /* air = data; */
    air = "\"" + data + "\"";
    getline(ss, data, ',');
    getline(ss, data, ',');
    /* source = data; */
    source = "\"" + data + "\"";
    getline(ss, data, ',');
    getline(ss, data, ',');
    /* dest = data; */
    dest = "\"" + data + "\"";
    g_.insertEdge(port_map[source], port_map[dest], air_map[air]);
    g_.setEdgeWeight(port_map[source], port_map[dest],
                     Airport::get_distance(port_map[source], port_map[dest], 'K'));
    
    lineGraph[air_map[air]].insertVertex(port_map[source]);
    lineGraph[air_map[air]].insertVertex(port_map[dest]);
    lineGraph[air_map[air]].insertEdge(port_map[source], port_map[dest], air_map[air]);
    lineGraph[air_map[air]].setEdgeWeight(port_map[source], port_map[dest], Airport::get_distance(port_map[source], port_map[dest], 'K'));
  }
  file_r.close();
}

void Airports::bfs(Vertex v, vector<Vertex> & path){
    std::queue<Vertex> q;
    vertices[v].set_label("visited");
    q.push(v);

    Vertex vert;
    

    while(!q.empty()){
        vert = q.front();
        path.push_back(vert);
        vector<Vertex> adj = g_.getAdjacent(vert);
        q.pop();

        for(unsigned x = 0; x < adj.size(); x++){
            if(vertices[adj[x]].get_label() == "unexplored"){
                g_.setEdgeLabel(vert,vertices[adj[x]],"discovery");
                vertices[vertices[adj[x]]].set_label("visited");
                q.push(vertices[adj[x]]);
            }
            else if(g_.getEdgeLabel(vert,vertices[adj[x]]) == "unexplored"){
                g_.setEdgeLabel(vert,vertices[adj[x]],"cross");
            }
        }
    }
}

void Airports::bfs() {
    vector<Vertex> path;
    vector<Vertex> verts = g_.getVertices();
    for(unsigned x = 0; x < verts.size(); x++){
        vertices.insert({verts[x], verts[x]});
        vertices[verts[x]].set_label("unexplored");
    }
    edges = g_.getEdges();

    for(unsigned x = 0; x < edges.size(); x++){
        Vertex sourc = edges[x].source;
        Vertex des = edges[x].dest;
        g_.setEdgeLabel(sourc, des, "unexplored");
    }
    for(unsigned x = 0; x < verts.size(); x++){
        if(vertices[verts[x]].get_label() == "unexplored"){
            bfs(vertices[verts[x]], path);
        }
    }

    for(unsigned x = 0; x < path.size()-1; x++){
        std::cout << path[x].get_name() << " -> " << path[x+1].get_name() << std::endl;
    }
}

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

void Airports::create_dijkstras(Airport a) {
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

std::vector<Vertex> Airports::getStronglyConnected(std::string airline) {
  Airline choice = air_map[airline];
  Graph g = lineGraph[choice];

  vector<Vertex> vertices = g.getVertices();

  std::map<Vertex, int> discover;
  std::map<Vertex, int> low;
  std::map<Vertex, bool> stackHasNode;
  std::stack<Vertex> s;
  std::set<Vertex> stronglyConnected;

  for (auto v : vertices) {
    discover[v] = -1;
    low[v] = -1;
    stackHasNode[v] = false;
  }

  for (auto v : vertices)
    if (discover[v] == -1)
      tarjanHelper(v, discover, low, s, stackHasNode, stronglyConnected, g);

  for(auto i : g.getVertices()) {
    for(auto j : g.getAdjacent(i)) {
      auto it = stronglyConnected.find(j);
      if(it != stronglyConnected.end())
        stronglyConnected.erase(it);
    }
  }
  vector<Vertex> ans(stronglyConnected.begin(), stronglyConnected.end());

  return ans;
}

void Airports::tarjanHelper(Vertex v, std::map<Vertex, int>& discover,
                            std::map<Vertex, int>& low, std::stack<Vertex>& s,
                            std::map<Vertex, bool>& stackHasNode,
                            std::set<Vertex>& stronglyConnected, Graph g) {
  static int time = 0;
  ++time;
  discover[v] = time;
  low[v] = time;
  s.push(v);
  stackHasNode[v] = true;
  auto adjacent = g.getAdjacent(v);

  for (auto adj : adjacent) {
    if (discover[adj] == -1) {
      tarjanHelper(adj, discover, low, s, stackHasNode, stronglyConnected, g);
      low[v] = std::min(low[v], low[adj]);
    } else if (stackHasNode[adj] == true)
      low[v] = std::min(low[v], discover[adj]);
  }

  Vertex temp;
  if (low[v] == discover[v]) {
    while (!s.empty() && s.top() != v) {
      temp = s.top();
      stronglyConnected.insert(temp);
      stackHasNode[temp] = false;
      s.pop();
    }
    if (!s.empty()) {
      temp = s.top();
      stronglyConnected.insert(temp);
      stackHasNode[temp] = false;
      s.pop();
    }
  }
}

std::map<Airline, vector<Vertex>> Airports::airlinesAdded() {
  std::map<Airline, vector<Vertex>> ans;
  for(auto i : airlines) {
    std::string name = i.get_IATA();
    if(name == "" || name == "\"\"" || name == "\\N")
      name = i.get_ICAO();
    if(name == "" || name == "\"\"" || name == "\\N")
      continue;
    vector<Vertex> temp = getStronglyConnected(name);
    if(!temp.empty())
      ans[i] = temp;
  }
  return ans;
}

vector<Vertex> Airports::getVertices() {
  return g_.getVertices();
}

vector<Edge> Airports::getEdges() {
  return g_.getEdges();
}

unordered_map<int, Airport> Airports::get_id_map(){
  return id_map;
}

Graph & Airports::get_graph(){
  return g_;
}
