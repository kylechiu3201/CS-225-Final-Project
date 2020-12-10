#define CATCH_CONFIG_MAIN

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "graph/graph.h"
#include "graph/edge.h"
#include "airports/airports.h"
#include "airport/airport.h"
#include "catch/catch.hpp"

using std::vector;

bool check_strong(vector<vector<std::string>> sol, vector<std::string> check) {
  std::sort(sol.begin(), sol.end());
  std::sort(check.begin(), check.end());
  for(unsigned i = 0; i < sol.size(); ++i) {
    auto pos = find(sol[i].begin(), sol[i].end(), check[i]);
    if(pos == sol[i].end())
      return false;
  }
  return true;
}

void to_text(Airports airports){
  std::ofstream file("small_file.txt", std::ofstream::out);
  file << airports.get_id_map().size() << "\n";
}

bool check_tol(double ans, double tol, double calc){
  return calc >= ans-tol && calc <= ans+tol;
}

TEST_CASE("Graph is created from small subset of data", "[weight=1][part=1]") {
  Airports airports("data/testairports.dat", "data/testairlines.dat", "data/testroutes.dat");

  REQUIRE(airports.getVertices().size()==11);
}

TEST_CASE("test lat/long distance calculation"){
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
  REQUIRE(2.004 ==Airport::get_distance(port1, port2, 'K'));
}

TEST_CASE("Correct fields for all vertices", "[weight=1][part=1]") {
  Airports airports("data/testairports.dat", "data/testairlines.dat", "data/testroutes.dat");
  vector<Vertex> vec = airports.getVertices();


  REQUIRE(vec.size()==11);

  vector<std::string> sol = {"ONE", "TWO", "THR", "FOU", "FIV", "SIX", "SEV", "EIG", "NIN", "TEN", "ELE"};
  vector<std::string> IATA;
  for(int x = 0 ; x<(int)vec.size();x++){
    IATA.push_back(vec[x].get_IATA());
  }
  REQUIRE(sol==IATA);


  REQUIRE(airports.get_graph().edgeExists(vec[0],vec[1]));
  double ans = 106.71;
  double tol = 0.01;
  //REQUIRE((airports.get_graph().getEdgeWeight(vec[0],vec[1]) >= ans-tol) && (airports.get_graph().getEdgeWeight(vec[0],vec[1])<=ans+tol));
  REQUIRE(check_tol(ans, tol, airports.get_graph().getEdgeWeight(vec[0],vec[1])));
}

TEST_CASE("Correct vertices for vertices of strongly connected graph of an airline with no inbound edges", "[weight=1][part=1]") {
  Airports airports("data/testairports.dat", "data/testairlines.dat", "data/teststronglyroutes.dat");
  /* Airports airports("data/testairports.dat", "data/testairlines.dat", "data/testroutes.dat"); */
  vector<Vertex> vec = airports.getStronglyConnected("\"EA\"");
  /* for(auto i : airports.getEdges()) */
  /*   std::cout << i.source.get_IATA() << " to " << i.dest.get_IATA() << std::endl; */
  /* for(auto i : vec) */
  /*   std::cout << i.get_IATA() << std::endl; */

  REQUIRE(vec.size() == 4);

  vector<std::string> check;
  for(auto i : vec)
    check.push_back(i.get_IATA());
  vector<vector<std::string>> sol = {{"ONE"}, {"THR", "FOU"}, {"FIV", "SIX"}, {"EIG", "NIN", "TEN"}, {"ELE"}};

  REQUIRE(check_strong(sol, check));
}
