#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

#include "airport.h"

Airport::Airport() {
  port_ID = -1;
  name_ = "";
  city_ = "";
  country_ = "";
  IATA_ = "\\N";
  ICAO_ = "\\N";
  latitude_ = 0;
  longitude_ = 0;
  label = "";
}

Airport::Airport(int port, string name, string city, string country,
                 string IATA, string ICAO, long double latitude,
                 long double longitude) {
  port_ID = port;
  name_ = name;
  name_.erase(remove(name_.begin(), name_.end(), '\"'), name_.end());
  city_ = city;
  city_.erase(remove(city_.begin(), city_.end(), '\"'), city_.end());
  country_ = country;
  country_.erase(remove(country_.begin(), country_.end(), '\"'),
                 country_.end());
  IATA_ = IATA;
  IATA_.erase(remove(IATA_.begin(), IATA_.end(), '\"'), IATA_.end());
  ICAO_ = ICAO;
  ICAO_.erase(remove(ICAO_.begin(), ICAO_.end(), '\"'), ICAO_.end());
  latitude_ = latitude;
  longitude_ = longitude;
  label = "";
}

int Airport::get_port_ID() const { return port_ID; }

string Airport::get_name() const { return name_; }

string Airport::get_city() const { return city_; }

string Airport::get_country() const { return country_; }

string Airport::get_IATA() const { return IATA_; }

string Airport::get_ICAO() const { return ICAO_; }

long double Airport::get_latitude() const { return latitude_; }

long double Airport::get_longitude() const { return longitude_; }

string Airport::get_label() const { return label; }

void Airport::set_lat(long double latitude) { latitude_ = latitude; }

void Airport::set_long(long double longitude) { longitude_ = longitude; }

void Airport::set_label(string l) { label = l; }

long double toRad(const long double degree) {
  long double conversion = (M_PI) / 180;
  return conversion * degree;
}

long double Airport::get_distance(const Airport& a, const Airport& b,
                                  char units) {
  if (b.longitude_ == a.longitude_ && b.latitude_ == a.latitude_) {
    return 0;
  }

  // long double long_d = toRad(b.longitude_) - toRad(a.longitude_);
  // long double lat_d = toRad(b.latitude_) - toRad(a.latitude_);

  long double dist = sin(toRad(a.latitude_)) * sin(toRad(b.latitude_)) +
                     cos(toRad(a.latitude_)) * cos(toRad(b.latitude_)) *
                         cos(toRad(a.longitude_ - b.longitude_));
  dist = acos(dist);
  dist = dist * 180 / M_PI;
  dist = dist * 60 * 1.1515;
  if (units == 'K') {
    dist *= 1.609344;
  }
  dist = round(dist * 1000.0) / 1000.0;
  return dist;
}

bool Airport::operator<(const Airport& a) const { return port_ID < a.port_ID; }

bool Airport::operator>(const Airport& a) const { return port_ID > a.port_ID; }

bool Airport::operator==(const Airport& a) const {
  return port_ID == a.port_ID;
}

bool Airport::operator!=(const Airport& a) const {
  return port_ID != a.port_ID;
}

ostream& operator<<(ostream& out, const Airport& obj) {
  out << "\"" << obj.name_ << "\",\"" << obj.city_ << "\",\"" << obj.country_ << "\"";
      //<< obj.IATA_ << "\",\"" << obj.ICAO_ << "\"," << obj.latitude_
      // << "," << obj.longitude_;
  return out;
}
