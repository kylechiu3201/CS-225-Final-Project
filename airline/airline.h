#pragma once

#include <iostream>
#include <string>

using std::ostream;

/**
 * @brief Airline class for the airline data
 */
class Airline {
 public:
  /**
   * @brief Constructor for default Airline object
   */
  Airline();

  /**
   * @brief Constructor for Airline object with the given parameters
   *
   * @param ID The ID of the airline
   * @param name The name of the airline
   * @param IATA The IATA code of the airline
   * @param ICAO The ICAO code of the airline
   * @param country The country of the airline
   */
  Airline(int ID, std::string name, std::string IATA, std::string ICAO,
          std::string country);

  /**
   * @brief Gets the ID of the airline
   *
   * @return  The ID of the airline
   */
  int get_ID();

  /**
   * @brief Gets the name of the airline
   *
   * @return The name of the airline
   */
  std::string get_name() const;

  /**
   * @brief Gets the IATA code of the airline
   *
   * @return The IATA code of the airline
   */
  std::string get_IATA() const;

  /**
   * @brief Gets the ICAO code of the airline
   *
   * @return The ICAO code of the airline
   */
  std::string get_ICAO() const;

  /**
   * @brief Gets the country of the airline
   *
   * @return The country of the airline
   */
  std::string get_country() const;

  /**
   * @brief Compares if the current airline > the chosen airline
   *
   * @param a The chosen airline
   *
   * @return If the current airline > the chosen airline
   */
  bool operator>(const Airline& a) const;

  /**
   * @brief Compares if the current airline < the chosen airline
   *
   * @param a The chosen airline
   *
   * @return If the current airline < the chosen airline
   */
  bool operator<(const Airline& a) const;

  /**
   * @brief Compares if the current airline == the chosen airline
   *
   * @param a The chosen airline
   *
   * @return If the current airline == the chosen airline
   */
  bool operator==(const Airline& a) const;

 private:
  int ID_;
  std::string name_;
  std::string IATA_;
  std::string ICAO_;
  std::string country_;

  /**
   * @brief Formats Airline data for easier output
   *
   * @param out The stream to output to
   * @param obj The Airline object to output
   *
   * @return The outputted stream
   */
  friend ostream& operator<<(ostream& out, const Airline& obj);
};
