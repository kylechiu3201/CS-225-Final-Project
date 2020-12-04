#include "airline.h"

Airline::Airline(std::string data) {}

int Airline::get_ID() { return ID_; }

std::string Airline::get_name() { return name_; }

std::string Airline::get_IATA() { return IATA_; }

std::string Airline::get_ICAO() { return ICAO_; }

std::string Airline::get_country() { return country_; }
