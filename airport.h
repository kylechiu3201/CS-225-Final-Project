#pragma once
#include <string>

using std::string;

class Airport{
    public:
    Airport();
    Airport(string data);
    int get_port_ID() const;
    string get_name();
    string get_city();
    string get_country();
    string get_IATA();
    string get_ICAO();
    double get_latitude();
    double get_longitude();
    bool operator<(const Airport & a) const;
    bool operator>(const Airport & a) const;
 private:
  int port_ID;
  string name_;
  string city_;
  string country_;
  string IATA_;
  string ICAO_;
  double latitude_;
  double longitude_;

};
