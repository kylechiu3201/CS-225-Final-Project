#include "airports.h"
#include <sstream>
#include <iostream>
#include <stdlib.h>

Airports::Airports(string filename) : g_(true){
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
    }
}
void Airports::bfs(){

}
void Airports::getDistance(string airport1, string airport2){
    
}
void Airports::getStronglyConnected(string airline){

}
