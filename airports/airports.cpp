#include "airports.h"

#include <stdlib.h>

#include <algorithm>
#include <fstream>
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

Airports::Airports(std::string filename, std::string fileair,
                   std::string fileroute)
    : g_(true, true) {
  // num_airports = 0;
  std::ifstream file(filename);
  
  std::ifstream file_a(fileair);
  
  std::ifstream file_r(fileroute);
  
  std::string str, name, city, country, IATA, ICAO;
  int port;
  double latitude, longitude;
  bool first = true;
  bool empty = true;
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
    if (IATA.compare("") != 0 && IATA.compare("\\N") != 0 && IATA != "\"\"") {
      //IATA.erase(remove(IATA.begin(), IATA.end(), '\"'), IATA.end());
      port_map.insert({IATA, airport_});
      g_.insertVertex(airport_);  // insert airports as vertexes
      empty = false;
    }
    if (ICAO.compare("") != 0 && ICAO.compare("\\N") != 0 && ICAO != "\"\"") {
      //ICAO.erase(remove(ICAO.begin(), ICAO.end(), '\"'), ICAO.end());
      port_map.insert({ICAO, airport_});
      g_.insertVertex(airport_);  // insert airports as vertexes
      empty = false;
    }
    /*if (ICAO.compare("") != 0 && ICAO.compare("\\N") != 0 "3\"\"") {
      //ICAO.erase(remove(ICAO.begin(), ICAO.end(), '\"'), ICAO.end());
      port_map.insert({ICAO, airport_});
      g_.insertVertex(airport_);  // insert airports as vertexes
    } */
                     
    if (first) {
      startingPort_ = airport_;
      first = false;
    }
    
    id_map[airport_.get_port_ID()] = airport_;
    // num_airports++;
  }
  file.close();

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
  if(empty){
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

    if (source.compare("\"\\N\"") != 0 && source != "\"\"" && dest.compare("\"\\N\"") != 0 && dest != "\"\"" && air.compare("\"\\N\"") != 0 && air != "\"\"") {
      g_.insertEdge(port_map[source], port_map[dest], air_map[air]);
      g_.setEdgeWeight(
        port_map[source], port_map[dest],
        Airport::get_distance(port_map[source], port_map[dest], 'K'));
    }
    

    lineGraph[air_map[air]].insertVertex(port_map[source]);
    lineGraph[air_map[air]].insertVertex(port_map[dest]);
    lineGraph[air_map[air]].insertEdge(port_map[source], port_map[dest],
                                       air_map[air]);
    lineGraph[air_map[air]].setEdgeWeight(
        port_map[source], port_map[dest],
        Airport::get_distance(port_map[source], port_map[dest], 'K'));
  }
  file_r.close();
}

void Airports::bfs_to_text(vector<vector<Airport>> v){
  std::ofstream file("BFS.txt", std::ofstream::out | std::ofstream::trunc);
  if(v.empty()){
    file << "Empty data set";
    return;
  }
  for(unsigned x = 0; x < v.size(); x++){
    file << "BFS " << x+1 << ":" << std::endl;
    for(unsigned y = 0; y < v[x].size(); y++){
      file << v[x][y] << std::endl;
    }
    file << std::endl;
  }
}

void Airports::bfs(Vertex v, vector<Vertex>& path) {
  std::queue<Vertex> q;
  vertices[v].set_label("visited");
  q.push(v);


  while(!q.empty()){
      Vertex vert = q.front();
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

vector<vector<Vertex>> Airports::bfs() {
  vector<vector<Vertex>> b; 
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
          vector<Vertex> path;
          bfs(vertices[verts[x]], path);
          if(!path.empty()){
            b.push_back(path);
          }
      }
  }

  return b;
}

void Airports::path_helper(int b, vector<Airport>& vec) {
  if (d_graph.parents[b] == -1) {
    return;
  }
  vec.insert(vec.begin(), id_map[d_graph.parents[b]]);
  path_helper(d_graph.parents[b], vec);
}

vector<Airport> Airports::shortest_path(
    std::string B) {  // currently returns name of each airport
  Airport b = port_map[B];
  int dest = b.get_port_ID();
  vector<Airport> shortest;
  path_helper(dest, shortest);
  shortest.push_back(b); //push destination
  return shortest;
}

long double Airports::shortest_dist(std::string B) {
  Airport b = port_map[B];
  return d_graph.distances[b.get_port_ID()]==INF ? -1 : d_graph.distances[b.get_port_ID()];
}

void Airports::shortest_to_text(std::string B){
  std::ofstream file("dijkstras.txt", std::ofstream::out | std::ofstream::trunc);
  vector<Airport> path_vector = shortest_path(B);
  int dist = shortest_dist(B);
  if(path_vector.size()==1){ 
    file << "Start: " << startingPort_.get_name() << "\",\"" << startingPort_.get_city() << "\",\"" << startingPort_.get_country() << "\""<<std::endl;
    file << "End: " << path_vector[0].get_name() << "\",\"" << path_vector[0].get_city() << "\",\"" << path_vector[0].get_country() << "\""<<std::endl;
    dist = -1;
    file << "No Path Available";
    return;
  }
  file << "Start: ";
  for(unsigned x =0; x<path_vector.size();x++){
    if(x==path_vector.size()-1){
      file << "End: " << path_vector[x].get_name() << "\",\"" << path_vector[x].get_city() << "\",\"" << path_vector[x].get_country() << "\""<<std::endl;
    }
    else{
      file << path_vector[x].get_name() << "\",\"" << path_vector[x].get_city() << "\",\"" << path_vector[x].get_country() << "\""<<std::endl;
    }
  }
  file << "Total distance: ";
  file << dist;
  file << " km";
}

vector<int> Airports::create_dijkstras(std::string A) {
  // cin somewhere and set starting airport
  // also figure out what to return::: shortest distance between two airports +
  // path to get there?
  //int pop_count = 0;
  vector<int> pop_vec;
  startingPort_ = port_map[A];
  Airport a = port_map[A];
  int start_id = a.get_port_ID();
  priority_queue<pair<long double, int>, vector<pair<long double, int>>,
                 std::greater<pair<long double, int>>>pq;  // long double is distance, second int is vertex/port_id
  unordered_map<int, int> parent;  // first is port_id, second is parent port_id
  unordered_map<int, long double> distance;  // first is port_id, second is distance
  unordered_set<int> visited;  //port_id

  vector<Vertex> vertices = g_.getVertices();
  for (auto v : vertices) {
    distance[v.get_port_ID()] = INF;
    parent[v.get_port_ID()] = -1;  // port id = -1 for default
  }
  distance[start_id] = 0;
  // handle starting airport
  pair<long double, int> airport_id = std::make_pair(0, start_id);
  pq.push(airport_id);

  while (!pq.empty()) {
    int u = pq.top().second;  // current airport id
    pq.pop();
    visited.insert(u);
    //pop_count++;
    pop_vec.push_back(u);
    //d_graph.graph.insertVertex(id_map[u]);
    vector<Vertex> vert = g_.getAdjacent(id_map[u]);
    for (int x = 0; x < (int)vert.size(); x++) {
      int v = vert[x].get_port_ID();  // child airport_id
      long double weight = g_.getEdgeWeight(id_map[u], vert[x]);

      // if vertex we are going to hasn't been processed yet  &&
      if (visited.find(v) == visited.end() &&
          distance[v] > distance[u] + weight) {
        distance[v] = distance[u] + weight;
        pq.push(std::make_pair(distance[v], v));
        parent[v] = u;
      }
    }
  }
  //pop_vec.push_back(pop_count);
  d_graph.distances = distance;
  d_graph.parents = parent;
  return pop_vec;
}

// Gets all strongly connected components with an in-degree of zero
std::vector<std::vector<Vertex>> Airports::getStronglyConnected(std::string airline) {
  Airline choice = air_map[airline];
  Graph g = lineGraph[choice];

  vector<Vertex> vertices = g.getVertices();

  std::map<Vertex, int> discover;
  std::map<Vertex, int> low;
  std::map<Vertex, bool> stackHasNode;
  std::stack<Vertex> s;
  std::vector<std::vector<Vertex>> stronglyConnected;

  for (auto v : vertices) {
    discover[v] = -1;
    low[v] = -1;
    stackHasNode[v] = false;
  }

  for (auto v : vertices)
    if (discover[v] == -1)
      tarjanHelper(v, discover, low, s, stackHasNode, stronglyConnected, g);

  for (auto i : g.getVertices()) {
    for (auto j : g.getAdjacent(i)) {
      for(auto k : stronglyConnected) {
        auto it = find(k.begin(), k.end(), j);
        if(it != k.end())
          k.erase(it);
        if(k.empty())
          stronglyConnected.erase(find(stronglyConnected.begin(), stronglyConnected.end(), k));
      }
    }
  }

  vector<vector<Vertex>> ans(stronglyConnected.begin(), stronglyConnected.end());
  return ans;
}

void Airports::tarjanHelper(Vertex v, std::map<Vertex, int>& discover,
                            std::map<Vertex, int>& low, std::stack<Vertex>& s,
                            std::map<Vertex, bool>& stackHasNode,
                            std::vector<std::vector<Vertex>>& stronglyConnected, Graph g) {
  static int time = 0;
  ++time;
  discover[v] = time;
  low[v] = time;
  s.push(v);
  stackHasNode[v] = true;

  for (auto adj : g.getAdjacent(v)) {
    if (discover[adj] == -1) {
      tarjanHelper(adj, discover, low, s, stackHasNode, stronglyConnected, g);
      low[v] = std::min(low[v], low[adj]);
    } else if (stackHasNode[adj] == true)
      low[v] = std::min(low[v], discover[adj]);
  }

  Vertex temp;
  if (low[v] == discover[v]) {
    std::vector<Vertex> component;
    while (!s.empty() && s.top() != v) {
      temp = s.top();
      component.push_back(temp);
      stackHasNode[temp] = false;
      s.pop();
    }
    if (!s.empty()) {
      temp = s.top();
      component.push_back(temp);
      stackHasNode[temp] = false;
      s.pop();
    }
    stronglyConnected.push_back(component);
  }
}

std::string Airports::airlinesAdded(std::string airline) {
  std::map<Airline, vector<vector<Vertex>>> ans;
  if (airline == "allAirlines") {
    std::cout << "Finding all needed airports for all airlines..." << std::endl;
    for (auto i : airlines) {
      std::string name = i.get_IATA();
      if (name == "" || name == "\"\"" || name == "\\N") name = i.get_ICAO();
      if (name == "" || name == "\"\"" || name == "\\N") continue;
      vector<vector<Vertex>> temp = getStronglyConnected(name);
      if (!temp.empty()) ans[i] = temp;
    }
  } else {
    vector<vector<Vertex>> temp = getStronglyConnected(airline);
    ans[air_map[airline]] = temp;
  }
  return exportStronglyConnected(ans);
}

vector<Vertex> Airports::getVertices() { return g_.getVertices(); }

vector<Edge> Airports::getEdges() { return g_.getEdges(); }

unordered_map<int, Airport> Airports::get_id_map() { return id_map; }

unordered_map<std::string, Airport> Airports::get_port_map() { return port_map; }

Graph& Airports::get_graph() { return g_; }

std::string Airports::exportStronglyConnected(
    map<Airline, vector<vector<Vertex>>> scc) {
  std::ofstream out;
  std::string filename = "allAirlinesNeeded";
  if (scc.empty()) return "empty";
  if (scc.size() == 1) {
    filename = scc.begin()->first.get_name();
    filename = filename.substr(1, filename.length() - 2);
  }
  std::string realFileName = filename + ".txt";
  std::ifstream file(filename + ".txt");
  if (!file.good())
    out.open(filename + ".txt", std::ios::out | std::ios::trunc);
  else {
    filename += " (";
    int repeats = 1;
    while (file.good()) {
      std::string save = filename + std::to_string(repeats++) + ").txt";
    //  file = std::ifstream(save);
      realFileName = save;
    }
    out.open(realFileName, std::ios::out | std::ios::trunc);
  }
  file.close();
  for(auto i : scc) {
    out << i.first << std::endl;
    for(auto j : i.second) {
      for(auto k : j)
        out << k << std::endl;
      out << std::endl;
    }
    out << std::endl << std::endl << std::endl;
  }
  out.close();
  return realFileName;
}
