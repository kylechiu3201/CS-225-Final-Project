#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

class Airport {

friend ostream& operator <<(ostream& out, const Airport& obj);
friend istream& operator >>(istream& in, const Airport& obj);



 public:
  Airport();
  Airport(int port, string name, string city, string country, string IATA,
          string ICAO, long double latitude, long double longitude);
  int get_port_ID() const;
  string get_name() const;
  string get_city() const;
  string get_country() const;
  string get_IATA() const;
  string get_ICAO() const;
  long double get_latitude() const;
  long double get_longitude() const;
  static long double get_distance(const Airport& a, const Airport& b, char units);
  string get_label() const;


  void set_lat(long double latitude);
  void set_long(long double longitude);
  void set_label(string l);


  bool operator<(const Airport& a) const;
  bool operator>(const Airport& a) const;
  bool operator==(const Airport& a) const;
  bool operator!=(const Airport& a) const;

 private:
  int port_ID;
  string name_;
  string city_;
  string country_;
  string IATA_;
  string ICAO_;
  long double latitude_;
  long double longitude_;
  string label;
};
