#include "airports.h"
#include <sstream>
#include <iostream>
#include <stdlib.h>

Airports::Airports() : g_(true){
    std::string filename;
    std::ifstream file(filename);
    if(file.fail()){
        std::cout << "Error opening file. Quitting..." << std::endl;
        exit(EXIT_FAILURE);
        return;
    }
    std::string str;
    while(std::getline(file,str)){
        Airport port(str);
        //insert vertex function
        g_.insertVertex(port);
    }
}
void Airports::bfs(){

}
void Airports::getDistance(){
    
}
void Airports::getStronglyConnected(){

}
