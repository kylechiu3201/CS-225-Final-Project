#pragma once
#include <string>

using std::string;

class Airport {
 private:
  int port_ID;
  string name_;
  string city_;
  string country_;
  string IATA_;
  string ICAO_;
  double latitude_;
  double longitude_;

 public:
  Airport();
  Airport(string data);
  int get_port_ID();
  string get_name();
  string get_city();
  string get_country();
  string get_IATA();
  string get_ICAO();
  double get_latitude();
  double get_longitude();
};
