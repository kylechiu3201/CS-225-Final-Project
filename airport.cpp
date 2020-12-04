#include "airport.h"
#include <bits/stdc++.h>

Airport::Airport(){
    port_ID = 0;
    name_ = "";
    city_ = "";
    country_ = "";
    IATA_ = "\\N";
    ICAO_ = "\\N";
    latitude_ = 0;
    longitude_ = 0;
}
Airport::Airport(string data){
    std::stringstream ss(data); //takes the line of data and puts them into fields
    string str;
    getline(ss,str, ',');
    port_ID = std::stoi(str);
    getline(ss,str, ',');
    name_ = str;
    getline(ss,str, ',');
    city_ = str;
    getline(ss,str, ',');
    country_ = str;
    getline(ss,str, ',');
    IATA_ = str;
    getline(ss,str, ',');
    ICAO_ = str;
    getline(ss,str, ',');
    latitude_ = std::stoi(str);
    getline(ss,str, ',');
    longitude_ = std::stoi(str);
}
int Airport::get_port_ID(){
    return port_ID;
}
string Airport::get_name(){
    return name_;
}
string Airport::get_city(){
    return city_;
}
string Airport::get_country(){
    return country_;
}
string Airport::get_IATA(){
    return IATA_;
}
string Airport::get_ICAO(){
    return ICAO_;
}
double Airport::get_latitude(){
    return latitude_;
}
double Airport::get_longitude(){
    return longitude_;
}