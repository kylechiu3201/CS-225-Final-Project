#include "airports.h"
#include <sstream>
#include <iostream>
#include <stdlib.h>

using std::string;

Airports::Airports() : g_(true){
    std::string filename;
    std::cout << "Enter airport data file name:" << std::endl; //read in airport data set
    std::cin >> filename;
    std::ifstream file(filename);
    if(file.fail()){
        std::cout << "Error opening file. Quitting..." << std::endl;
        exit(EXIT_FAILURE);
        return;
    }
    std::string str, name, city, country, IATA, ICAO;
    int port;
    double latitude, longitude;

    while(std::getline(file,str)){
        std::stringstream ss(str);  // takes the line of data and puts them into fields
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
        Airport airport_(port, name, city, country, IATA, ICAO, latitude, longitude);
        g_.insertVertex(airport_); //insert airports as vertexes
        if(IATA.compare("") != 0 && IATA.compare("\\N") != 0){
            port_map.insert({IATA,airport_});
        }
        if(ICAO.compare("") != 0 && ICAO.compare("\\N") != 0){
            port_map.insert({ICAO,airport_});
        }
    }
    file.close();

    std::string fileair;
    std::cout << "Enter airline data file name:" << std::endl; //read in route data set
    std::cin >> fileair;
    std::ifstream file_a(fileair);
    int ID;

    while(std::getline(file_a,str)){
        std::stringstream ss(str);  // takes the line of data and puts them into fields
        string data;
        getline(ss, data, ',');
        ID = std::stoi(data);
        getline(ss, data, ',');
        name = data;
        getline(ss, data, ',');
        getline(ss, data, ',');
        IATA = data.substr(1,data.size()-2);
        getline(ss, data, ',');
        ICAO = data.substr(1,data.size()-2);
        getline(ss, data, ',');
        getline(ss, data, ',');
        country = data;

        Airline airline_(ID,name,IATA,ICAO,country);
        if(IATA.compare("") != 0 && IATA.compare("\\N") != 0){
            air_map.insert({IATA,airline_});
        }
        if(ICAO.compare("") != 0 && ICAO.compare("\\N") != 0){
            air_map.insert({ICAO,airline_});
        }
    }
    file_a.close();
    std::string fileroute;
    std::cout << "Enter route data file name:" << std::endl; //read in route data set
    std::cin >> fileroute;
    std::ifstream file_r(fileroute);
    while(std::getline(file_r,str)){
        std::stringstream ss(str);  // takes the line of data and puts them into fields
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
        g_.setEdgeWeight(port_map[source], port_map[dest], Airport::get_distance(port_map[source],port_map[dest]));
    }
    file_r.close();

}
void Airports::bfs(){

}

void Airports::shortest_path(Airport a, Airport b){

}

void Airports::getStronglyConnected(){

}
