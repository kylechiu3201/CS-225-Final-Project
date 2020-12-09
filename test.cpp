#define CATCH_CONFIG_MAIN

#include <iostream>
#include <fstream>

#include "graph/graph.h"
#include "graph/edge.h"
#include "airports/airports.h"
#include "airport/airport.h"
#include "catch/catch.hpp"

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


TEST_CASE("Graph is created from small subset of data", "[weight=1][part=1]") {
  Airports airports("data/testairports.dat", "data/testairlines.dat", "data/testroutes.dat");

  
  REQUIRE(airports.getVertices().size()==11);
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

