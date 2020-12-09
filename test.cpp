#define CATCH_CONFIG_MAIN

#include <iostream>
#include <fstream>
#include <vector>

#include "graph/graph.h"
#include "graph/edge.h"
#include "airports/airports.h"
#include "airport/airport.h"
#include "catch/catch.hpp"

using std::vector;

void printGraph(Airports airports) {
  //Vertices are fine
  std::cout << "Vertices: " << std::endl;
  auto vertices = airports.getVertices();
  auto edges = airports.getEdges();
  for(auto v : vertices)
    /* std::cout << v.get_port_ID() << std::endl; */
    std::cout << v.get_ICAO() << std::endl;
  std::cout << std::endl << std::endl << std::endl;
  for(auto e : edges)
    std::cout << e.source.get_port_ID() << " to " << e.dest.get_port_ID() << std::endl;
}


void to_text(Airports airports){
  std::ofstream file("small_file.txt", std::ofstream::out);
  file << airports.get_id_map().size() << "\n";
}

bool check_tol(double ans, double tol, double calc){
  return calc >= ans-tol && calc <= ans+tol;
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
  //Airports airports("data/testairports.dat", "data/testairlines.dat", "data/testroutes.dat");
  /* Airports airports("data/airports.dat", "data/airlines.dat", "data/routes.dat"); */
  //printGraph(airports);
  /* std::string command; */
  /* bool done = false; */
  /* while(!done) { */
  /*   std::cout << "\nChoose a command: getDist, airlinesNeeded, bfs, exit\n"; */
  /*   std::cin >> command; */
  /*   // if(command == "getDist") */
  /*   //   airports.shortest_path(); */
  /*   if(command == "airlinesNeeded") */
  /*     airports.getStronglyConnected(); */
  /*   else if(command == "bfs") */
  /*     airports.bfs(); */
  /*   else if(command == "exit") */
  /*     done = true; */
  /*   else */
  /*     std::cout << "'" << command << "' is not a recognized command.\n"; */
  /* } */

