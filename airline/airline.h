#pragma once
#include <string>
#include <iostream>

using std::ostream;

class Airline {
 public:
  Airline();
  Airline(int ID, std::string name, std::string IATA, std::string ICAO,
          std::string country);
  int get_ID();
  std::string get_name() const;
  std::string get_IATA() const;
  std::string get_ICAO() const;
  std::string get_country() const;
  bool operator>(const Airline& a) const;
  bool operator<(const Airline& a) const;
  bool operator==(const Airline& a) const;

 private:
  int ID_;
  std::string name_;
  std::string IATA_;
  std::string ICAO_;
  std::string country_;
  friend ostream& operator <<(ostream& out, const Airline& obj);
};
