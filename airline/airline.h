#pragma once
#include <string>

class Airline {
 public:
  Airline(std::string data);
  int get_ID();
  std::string get_name();
  std::string get_IATA();
  std::string get_ICAO();
  std::string get_country();
  

 private:
  int ID_;
  std::string name_;
  std::string IATA_;
  std::string ICAO_;
  std::string country_;
  
};
