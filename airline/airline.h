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
  // The ID of the airline
  int ID_;

  // The name of the airline
  std::string name_;

  // The IATA code of the airline
  std::string IATA_;

  // The ICAO code of the airline
  std::string ICAO_;

  // The country of the airline
  std::string country_;

  // Overloads << for easier output of the data
  friend ostream& operator<<(ostream& out, const Airline& obj);
};
