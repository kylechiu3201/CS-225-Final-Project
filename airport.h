#pragma once
#include <string>

using std::string;

class Airport{
    public:
    Airport();
    Airport(string data);
    int get_port_ID() const;
    string get_name() const;
    string get_city() const;
    string get_country() const;
    string get_IATA() const ;
    string get_ICAO() const;
    double get_latitude() const;
    double get_longitude() const;
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
