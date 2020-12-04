#include "airport.h"

#include <sstream>

Airport::Airport() {
  port_ID = 0;
  name_ = "";
  city_ = "";
  country_ = "";
  IATA_ = "\\N";
  ICAO_ = "\\N";
  latitude_ = 0;
  longitude_ = 0;
}

Airport::Airport(int port, string name, string city, string country, string IATA, string ICAO, double latitude, double longitude) {
  port_ID = port;
  name_ = name;
  city_ = city;
  country_ = country;
  IATA_ = IATA;
  ICAO_ = ICAO;
  latitude_ = latitude;
  longitude_ = longitude;
}

int Airport::get_port_ID() const { return port_ID; }

string Airport::get_name() const { return name_; }

string Airport::get_city() const { return city_; }

string Airport::get_country() const { return country_; }

string Airport::get_IATA() const { return IATA_; }

string Airport::get_ICAO() const { return ICAO_; }

double Airport::get_latitude() const { return latitude_; }

double Airport::get_longitude() const { return longitude_; }

bool Airport::operator<(const Airport& a) const {
  if (port_ID < a.port_ID) {
    return true;
  }
  return false;
}

bool Airport::operator>(const Airport& a) const {
  if (port_ID == a.port_ID) {
    return true;
  } else {
    return false;
  }
}
