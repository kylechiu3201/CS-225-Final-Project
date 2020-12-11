#pragma once
#include <iostream>
#include <string>

using std::ostream;

class Airline {
 public:
  // Creates an empty Airline object with all default values
  Airline();
  // Creates an Airline object with the given parameter values
  Airline(int ID, std::string name, std::string IATA, std::string ICAO,
          std::string country);
  // Returns the Airline ID
  int get_ID();
  // Returns the Airline name
  std::string get_name() const;
  // Returns the Airline IATA
  std::string get_IATA() const;
  // Returns the Airline ICAO
  std::string get_ICAO() const;
  // Returns the Airline country
  std::string get_country() const;
  // Compares the IATA/ICAO of the Airline for operator>
  bool operator>(const Airline& a) const;
  // Compares the IATA/ICAO of the Airline for operator<
  bool operator<(const Airline& a) const;
  // Compares the IATA/ICAO of the Airline for operator==
  bool operator==(const Airline& a) const;

 private:
  // Instance variables
  int ID_;
  std::string name_;
  std::string IATA_;
  std::string ICAO_;
  std::string country_;
  // Overloads << for easier output of the data
  friend ostream& operator<<(ostream& out, const Airline& obj);
};
