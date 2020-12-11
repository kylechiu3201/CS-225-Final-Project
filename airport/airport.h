#pragma once
#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

class Airport {
 public:
  // Creates an empty Airport object with default values
  Airport();

  // Creates an Airport object with the given parameters
  Airport(int port, string name, string city, string country, string IATA,
          string ICAO, long double latitude, long double longitude);

  // Gets the ID of the airport
  int get_port_ID() const;

  // Gets the name of the airport
  string get_name() const;

  // Gets the city of the airport
  string get_city() const;

  // Gets the country of the airport
  string get_country() const;

  // Gets the IATA code of the airport
  string get_IATA() const;

  // Gets the ICAO code of the airport
  string get_ICAO() const;

  // Gets the latitude coordinate of the airport
  long double get_latitude() const;

  // Gets the longitude coordinate of the airport
  long double get_longitude() const;

  // Gets the distance from one airport to another
  static long double get_distance(const Airport& a, const Airport& b,
                                  char units);

  // Gets the label of the airport
  string get_label() const;

  // Sets the latitude coordinate of the airport
  void set_lat(long double latitude);

  // Sets the longitude coordinate of the airport
  void set_long(long double longitude);

  // Sets the label of the airport
  void set_label(string l);

  // Compares if current airport < given airport
  bool operator<(const Airport& a) const;

  // Compares if current airport > given airport
  bool operator>(const Airport& a) const;

  // Compares if current airport == given airport
  bool operator==(const Airport& a) const;

  // Compares if current airport != given airport
  bool operator!=(const Airport& a) const;

 private:
  // The ID of the airport
  int port_ID;

  // The name of the airport
  string name_;

  // The city of the airport
  string city_;

  // The country of the airport
  string country_;

  // The IATA code of the airport
  string IATA_;

  // The ICAO code of the airport
  string ICAO_;

  // The latitude coordinate of the airport
  long double latitude_;

  // The longitude coordinate of the airport
  long double longitude_;

  // The label of the airport
  string label;

  // Formats output of the Airport object data for easier outputting
  friend ostream& operator<<(ostream& out, const Airport& obj);

  //friend istream& operator>>(istream& in, const Airport& obj);
};
