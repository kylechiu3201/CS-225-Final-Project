#pragma once

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

/**
 * @brief Airport class for airport data
 */
class Airport {
 public:
  /**
   * @brief Constructor for default Airport object
   */
  Airport();

  /**
   * @brief Constructor for Airport object with given parameters
   *
   * @param port The ID of the airport
   * @param name The name of the airport
   * @param city The city of the airport
   * @param country The country of the airport
   * @param IATA The IATA code of the airport
   * @param ICAO The ICAO code of the airport
   * @param latitude The latitude coordinate of the airport
   * @param longitude The longitude coordinate of the airport
   */
  Airport(int port, string name, string city, string country, string IATA,
          string ICAO, long double latitude, long double longitude);

  /**
   * @brief Gets the ID of the airport
   *
   * @return The ID of the airport
   */
  int get_port_ID() const;

  /**
   * @brief Gets the name of the airport
   *
   * @return The name of the airport
   */
  string get_name() const;

  /**
   * @brief Gets the city of the airport
   *
   * @return The city of the airport
   */
  string get_city() const;

  /**
   * @brief Gets the country of the airport
   *
   * @return The country of the airport
   */
  string get_country() const;

  /**
   * @brief Gets the IATA code of the airport
   *
   * @return The IATA code of the airport
   */
  string get_IATA() const;

  /**
   * @brief Gets the ICAO code of the airport
   *
   * @return The ICAO code of the airport
   */
  string get_ICAO() const;

  /**
   * @brief Gets the latitude coordinate of the airport
   *
   * @return The latitude coordinate of the airport
   */
  long double get_latitude() const;

  /**
   * @brief Gets the longitude coordinate of the airport
   *
   * @return The longitude coordinate of the airport
   */
  long double get_longitude() const;

  /**
   * @brief Gets the distance from one airport to another
   *
   * @param a The first airport
   * @param b The second airport
   * @param units The units of the distance
   *
   * @return The distance from one airport to another
   */
  static long double get_distance(const Airport& a, const Airport& b,
                                  char units);

  /**
   * @brief Gets the label of the airport
   *
   * @return The label of the airport
   */
  string get_label() const;

  /**
   * @brief Sets the latitude coordinate of the airport
   *
   * @param latitude The latitude coordinate of the airport
   */
  void set_lat(long double latitude);

  /**
   * @brief Sets the longitude coordinate of the airport
   *
   * @param longitude The longitude coordinate of the airport
   */
  void set_long(long double longitude);

  /**
   * @brief Sets the label of the airport
   *
   * @param l The label of the airport
   */
  void set_label(string l);

  /**
   * @brief Compares if the current airport < the chosen airport
   *
   * @param a The chosen airport to compare to
   *
   * @return If the current airport < the chosen airport
   */
  bool operator<(const Airport& a) const;

  /**
   * @brief Compares if the current airport > the chosen airport
   *
   * @param a The chosen airport to compare to
   *
   * @return If the current airport > the chosen airport
   */
  bool operator>(const Airport& a) const;

  /**
   * @brief Compares if the current airport == the chosen airport
   *
   * @param a The chosen airport to compare to
   *
   * @return If the current airport == the chosen airport
   */
  bool operator==(const Airport& a) const;

  /**
   * @brief Compares if the current airport != the chosen airport
   *
   * @param a The chosen airport to compare to
   *
   * @return If the current airport != the chosen airport
   */
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

  /**
   * @brief Formats output of Airport data for easier outputting
   *
   * @param out The stream to output to
   * @param obj The Airport object to output
   *
   * @return The outputted stream
   */
  friend ostream& operator<<(ostream& out, const Airport& obj);
  // friend istream& operator>>(istream& in, const Airport& obj);
};
