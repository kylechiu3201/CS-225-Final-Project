#include "airline.h"

Airline::Airline(){
    
}
Airline::Airline(int ID, std::string name, std::string IATA, std::string ICAO,
                 std::string country) {
  ID_ = ID;
  name_ = name;
  IATA_ = IATA;
  ICAO_ = ICAO;
  country_ = country;
}

int Airline::get_ID() { return ID_; }

std::string Airline::get_name() { return name_; }

std::string Airline::get_IATA() { return IATA_; }

std::string Airline::get_ICAO() { return ICAO_; }

std::string Airline::get_country() { return country_; }
