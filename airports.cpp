#include "airports.h"
#include <sstream>
#include <iostream>
#include <stdlib.h>

using std::string;

Airports::Airports(string filename ) : g_(true){
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
        port = std::stoi(str);
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
        //insert vertex function
        g_.insertVertex(airport_);
    }
}
void Airports::bfs(){

}
void Airports::getDistance(string airport1, string airport2){

}
void Airports::getStronglyConnected(string airline){

}
