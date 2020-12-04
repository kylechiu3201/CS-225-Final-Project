#pragma once
#include <string>

class Airline {
 public:
  Airline(std::string data);
  std::string get_name();
  std::string get_alias();
  std::string get_IATA();
  std::string get_ICAO();
  std::string get_callsign();
  std::string get_country();
  bool is_active();

 private:
  int ID_;
  std::string name_;
  std::string alias_;
  std::string IATA_;
  std::string ICAO_;
  std::string callsign_;
  std::string country_;
  bool active_;
};
