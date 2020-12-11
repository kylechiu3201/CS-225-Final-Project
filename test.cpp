#define CATCH_CONFIG_MAIN

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "airport/airport.h"
#include "airports/airports.h"
#include "catch/catch.hpp"
#include "graph/edge.h"
#include "graph/graph.h"

using std::vector;

void printGraph(Airports airports) {
  // Vertices are fine
  std::cout << "Vertices: " << std::endl;
  auto vertices = airports.getVertices();
  auto edges = airports.getEdges();
  for (auto v : vertices) /* std::cout << v.get_port_ID() << std::endl; */
    std::cout << v.get_ICAO() << std::endl;
  std::cout << std::endl << std::endl << std::endl;
  for (auto e : edges)
    std::cout << e.source.get_port_ID() << " to " << e.dest.get_port_ID()
              << std::endl;
}

bool check_dup(vector<int> vec) {
  unordered_map<int, int> m;
  for (auto ele : vec) {
    m[ele]++;
    if (m[ele] == 2) {
      return true;
    }
  }
  return false;
}

bool check_tol(double ans, double tol, double calc) {
  return calc >= ans - tol && calc <= ans + tol;
}

bool bfs_test(vector<Vertex> path, vector<std::string> sol) {
  REQUIRE(path.size() == sol.size());
  for (unsigned x = 0; x < path.size(); x++) {
    REQUIRE(path[x].get_name() == sol[x]);
  }
  return true;
}

bool bfs_comp(vector<vector<Vertex>> b, vector<vector<std::string>> sol) {
  REQUIRE(b.size() == sol.size());
  for (unsigned x = 0; x < b.size(); x++) {
    REQUIRE(b[x].size() == sol[x].size());
    for (unsigned y = 0; y < b[x].size(); y++) {
      REQUIRE(b[x][y].get_name() == sol[x][y]);
    }
  }
  return true;
}

TEST_CASE("Graph is created from small subset of data", "[weight=1][part=1]") {
  Airports airports("data/testairports.dat", "data/testairlines.dat",
                    "data/testroutes.dat");

  REQUIRE(airports.getVertices().size() == 11);
}

TEST_CASE("test lat/long distance calculation") {
  Airport port1;
  port1.set_lat(53.32055555555556);
  port1.set_long(-1.7297222222222221);

  Airport port2;
  port2.set_lat(53.32055555555556);
  port2.set_long(-1.7297222222222221);

  REQUIRE(0 == Airport::get_distance(port1, port2, 'K'));

  port1.set_lat(53.32055555555556);
  port1.set_long(-1.7297222222222221);

  port2.set_lat(53.31861111111111);
  port2.set_long(-1.6997222222222223);
  REQUIRE(2.004 == Airport::get_distance(port1, port2, 'K'));
}

TEST_CASE("Correct fields for vertices", "[weight=1][part=1]") {
  Airports airports("data/testairports.dat", "data/testairlines.dat",
                    "data/testroutes.dat");
  vector<Vertex> vec = airports.getVertices();

  REQUIRE(vec.size() == 11);

  vector<std::string> sol = {"ONE", "TWO", "THR", "FOU", "FIV", "SIX",
                             "SEV", "EIG", "NIN", "TEN", "ELE"};
  vector<std::string> IATA;
  for (int x = 0; x < (int)vec.size(); x++) {
    IATA.push_back(vec[x].get_IATA());
  }
  REQUIRE(sol == IATA);

  REQUIRE(airports.get_graph().edgeExists(vec[0], vec[1]));
  double ans = 106.71;
  double tol = 0.01;
  // REQUIRE((airports.get_graph().getEdgeWeight(vec[0],vec[1]) >= ans-tol) &&
  // (airports.get_graph().getEdgeWeight(vec[0],vec[1])<=ans+tol));
  REQUIRE(
      check_tol(ans, tol, airports.get_graph().getEdgeWeight(vec[0], vec[1])));
}

TEST_CASE("dijkstras- no path available") {
  std::ofstream file("data/dtest.dat",
                     std::ofstream::out | std::ofstream::trunc);
  file << "UAL,1,ONEE,1,TWO,2,123,,0,jun" << std::endl;
  file << "SW,2,TWO,2,THR,3,123,,0,jun" << std::endl;

  Airports airports("data/testairports.dat", "data/testairlines.dat",
                    "data/dtest.dat");
  airports.create_dijkstras("\"ONE\"");
  vector<Vertex> path = airports.shortest_path("\"FOUR\"");
  REQUIRE(path.size() == 1);  // If path size is 1, then no path exists.
}

TEST_CASE("dijkstras - graph with forward/back edges") {
  std::ofstream file("data/dtest.dat",
                     std::ofstream::out | std::ofstream::trunc);
  file << "UAL,1,ONEE,1,TWO,2,123,,0,jun" << std::endl;
  file << "UAL,1,TWO,1,ONEE,2,123,,0,jun" << std::endl;
  file << "SW,2,TWO,2,THR,3,123,,0,jun" << std::endl;
  file << "SW,2,THR,2,TWO,3,123,,0,jun" << std::endl;

  Airports airports("data/testairports.dat", "data/testairlines.dat",
                    "data/dtest.dat");
  airports.create_dijkstras("\"ONE\"");
  vector<Vertex> path = airports.shortest_path("\"THR\"");
  airports.shortest_to_text("\"THR\"");
  REQUIRE(path.size() == 3);

  REQUIRE(path[0].get_name() == "name 1");
  REQUIRE(path[1].get_name() == "name 2");
  REQUIRE(path[2].get_name() == "name 3");
}

TEST_CASE("dijkstras - takes shorter path") {
  std::ofstream file("data/dtest.dat",
                     std::ofstream::out | std::ofstream::trunc);
  file << "UAL,1,ONEE,1,TWO,2,123,,0,jun" << std::endl;
  file << "UAL,1,TWO,1,ONEE,2,123,,0,jun" << std::endl;
  file << "SW,2,TWO,2,THR,3,123,,0,jun" << std::endl;
  file << "SW,2,THR,2,TWO,3,123,,0,jun" << std::endl;
  file << "EVA,4,THRE,3,FOU,4,123,,0,jun" << std::endl;
  file << "EVA,4,FOU,3,FIVE,4,123,,0,jun" << std::endl;
  file << "UAL,1,ONEE,1,FOU,2,123,,0,jun" << std::endl;

  Airports airports("data/testairports.dat", "data/testairlines.dat",
                    "data/dtest.dat");
  airports.create_dijkstras("\"ONE\"");
  vector<Vertex> path = airports.shortest_path("\"FIVE\"");
  airports.shortest_to_text("\"FIVE\"");
  REQUIRE(path.size() == 3);

  REQUIRE(path[0].get_name() == "name 1");
  REQUIRE(path[1].get_name() == "name 4");
  REQUIRE(path[2].get_name() == "name 5");

  Graph g = airports.get_graph();
  double short_dist = g.getEdgeWeight(airports.get_port_map()["\"ONE\""],
                                      airports.get_port_map()["\"FOUR\""]) +
                      g.getEdgeWeight(airports.get_port_map()["\"FOUR\""],
                                      airports.get_port_map()["\"FIVE\""]);
  REQUIRE(short_dist == airports.shortest_dist("\"FIVE\""));

  double long_dist = g.getEdgeWeight(airports.get_port_map()["\"ONEE\""],
                                     airports.get_port_map()["\"TWO\""]) +
                     g.getEdgeWeight(airports.get_port_map()["\"TWO\""],
                                     airports.get_port_map()["\"THR\""]) +
                     g.getEdgeWeight(airports.get_port_map()["\"THRE\""],
                                     airports.get_port_map()["\"FOU\""]) +
                     g.getEdgeWeight(airports.get_port_map()["\"FOU\""],
                                     airports.get_port_map()["\"FIVE\""]);
  REQUIRE(long_dist > short_dist);
}

TEST_CASE("dijkstras - checks node only if necessary (efficiency)") {
  std::ofstream file("data/dtest.dat",
                     std::ofstream::out | std::ofstream::trunc);
  file << "UAL,1,ONEE,1,TWO,2,123,,0,jun" << std::endl;
  file << "UAL,1,TWO,1,ONEE,2,123,,0,jun" << std::endl;
  file << "SW,2,TWO,2,THR,3,123,,0,jun" << std::endl;
  file << "SW,2,THR,2,TWO,3,123,,0,jun" << std::endl;
  file << "EVA,4,THRE,3,FOU,4,123,,0,jun" << std::endl;
  file << "EVA,4,FOU,3,FIVE,4,123,,0,jun" << std::endl;
  file << "UAL,1,ONEE,1,FOU,2,123,,0,jun" << std::endl;
  file << "UAL,1,ONEE,1,TEN,2,123,,0,jun" << std::endl;
  Airports airports("data/testairports.dat", "data/testairlines.dat",
                    "data/dtest.dat");
  vector<int> check = airports.create_dijkstras("\"ONEE\"");
  // for(int x =0 ; x<(int)check.size();x++){
  //   std::cout << check[x] << " ";
  // }
  REQUIRE(check.size() == 6);
}

TEST_CASE("dijkstras - checks node each node once (efficiency)") {
  Airports airports("data/testairports.dat", "data/testairlines.dat",
                    "data/testroutes.dat");
  vector<int> check = airports.create_dijkstras("\"ONEE\"");
  // for(int x =0 ; x<(int)check.size();x++){
  //   std::cout << check[x] << " ";
  // }
  REQUIRE(check.size() == 11);
  REQUIRE(check_dup(check) == false);
}

TEST_CASE(
    "Correct vertices for vertices of strongly connected graph of an airline "
    "with no inbound edges",
    "[weight=1][part=1]") {
  Airports airports("data/testairports.dat", "data/testairlines.dat",
                    "data/teststronglyroutes.dat");
  vector<vector<Vertex>> vec = airports.getStronglyConnected("\"EA\"");

  REQUIRE(vec.size() == 4);

  vector<vector<std::string>> check;
  for (auto i : vec) {
    vector<std::string> temp;
    for (auto j : i) temp.push_back(j.get_IATA());
    check.push_back(temp);
  }
  vector<vector<std::string>> sol = {
      {"ONE"}, {"THR", "FOU"}, {"FIV", "SIX"}, {"EIG", "NIN", "TEN"}, {"ELE"}};

  REQUIRE(sol == check);
}

TEST_CASE("BFS - empty data set") {
  std::ofstream file("data/bfstest.dat",
                     std::ofstream::out | std::ofstream::trunc);

  Airports airports("data/bfstest.dat", "data/testairlines.dat",
                    "data/testroutes.dat");
  vector<vector<Vertex>> b = airports.bfs();
  vector<Vertex> path;
  for (unsigned x = 0; x < b.size(); x++) {
    for (unsigned y = 0; y < b[x].size(); y++) {
      path.push_back(b[x][y]);
    }
  }

  REQUIRE(path.size() == 0);
}

TEST_CASE("BFS - Traverses the whole graph with the correct path") {
  std::ofstream file("data/bfstest.dat",
                     std::ofstream::out | std::ofstream::trunc);
  file << "SW,2,ONEE,1,TWO,2,123,,0,jun" << std::endl;
  file << "SW,2,ONEE,1,FOUR,4,123,,0,jun" << std::endl;
  file << "SW,2,FOUR,4,THR,3,123,,0,jun" << std::endl;
  file << "SW,2,FOUR,4,SIX,6,123,,0,jun" << std::endl;
  file << "SW,2,SIX,6,SEVE,7,123,,0,jun" << std::endl;
  file << "SW,2,SEVE,7,FIVE,5,123,,0,jun" << std::endl;
  file << "SW,2,FIVE,5,EIG,8,123,,0,jun" << std::endl;
  file << "SW,2,EIG,8,NINE,9,123,,0,jun" << std::endl;
  file << "SW,2,NINE,9,TEN,10,123,,0,jun" << std::endl;
  file << "SW,2,TEN,10,ELE,11,123,,0,jun" << std::endl;

  Airports airports("data/testairports.dat", "data/testairlines.dat",
                    "data/bfstest.dat");
  vector<vector<Vertex>> b = airports.bfs();
  vector<Vertex> path;

  REQUIRE(b.size() == 1);  // traversal is connected

  for (unsigned x = 0; x < b.size(); x++) {
    for (unsigned y = 0; y < b[x].size(); y++) {
      path.push_back(b[x][y]);
    }
  }

  REQUIRE(path.size() == 11);

  vector<std::string> sol = {"name 1", "name 2",  "name 4", "name 3",
                             "name 6", "name 7",  "name 5", "name 8",
                             "name 9", "name 10", "name 11"};

  REQUIRE(bfs_test(path, sol));
}

TEST_CASE("BFS - Traverse a graph with multiple components") {
  std::ofstream file("data/bfstest.dat",
                     std::ofstream::out | std::ofstream::trunc);
  file << "SW,2,ONEE,1,TWO,2,123,,0,jun" << std::endl;
  file << "SW,2,TWO,2,THR,3,123,,0,jun" << std::endl;

  file << "SW,2,FOUR,4,SIX,6,123,,0,jun" << std::endl;
  file << "SW,2,SIX,6,SEVE,7,123,,0,jun" << std::endl;
  file << "SW,2,SEVE,7,FIVE,5,123,,0,jun" << std::endl;
  file << "SW,2,FIVE,5,EIG,8,123,,0,jun" << std::endl;

  Airports airports("data/testairports.dat", "data/testairlines.dat",
                    "data/bfstest.dat");
  vector<vector<Vertex>> b = airports.bfs();

  REQUIRE(b.size() == 5);

  vector<vector<std::string>> sol = {
      {"name 1", "name 2", "name 3"},
      {"name 4", "name 6", "name 7", "name 5", "name 8"},
      {"name 9"},
      {"name 10"},
      {"name 11"}};

  REQUIRE(bfs_comp(b, sol));
}
