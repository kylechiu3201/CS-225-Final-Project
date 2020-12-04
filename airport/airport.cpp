#include "airport.h"

#include <sstream>
#include <cmath>

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

long double Airport::get_latitude() const { return latitude_; }

long double Airport::get_longitude() const { return longitude_; }

double Airport::get_distance(const Airport & a, const Airport & b){
  long double long_d = b.longitude_ - a.longitude_;
  long double lat_d = b.latitude_ - a.latitude_;

  long double dist = pow(sin(lat_d / 2), 2) +  
                          cos(a.latitude_) * cos(b.latitude_) *  
                          pow(sin(long_d / 2), 2); 
  dist = asin(sqrt(dist)) *2 * 6371;
  return dist;
}

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
