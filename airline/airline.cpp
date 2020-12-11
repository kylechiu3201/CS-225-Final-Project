#include "airline.h"

// Creates an empty Airline object with all default values
Airline::Airline() {}

// Creates an Airline object with the given parameter values
Airline::Airline(int ID, std::string name, std::string IATA, std::string ICAO,
                 std::string country) {
  ID_ = ID;
  name_ = name;
  IATA_ = IATA;
  ICAO_ = ICAO;
  country_ = country;
}

// Returns the Airline ID
int Airline::get_ID() { return ID_; }

// Returns the Airline name
std::string Airline::get_name() const { return name_; }

// Returns the Airline IATA
std::string Airline::get_IATA() const { return IATA_; }

// Returns the Airline ICAO
std::string Airline::get_ICAO() const { return ICAO_; }

// Returns the Airline country
std::string Airline::get_country() const { return country_; }

// Compares the IATA/ICAO of the Airline for operator>
bool Airline::operator>(const Airline& a) const {
  if (IATA_ != "" && a.IATA_ != "") return IATA_ > a.IATA_;
  return ICAO_ > a.ICAO_;
}

// Compares the IATA/ICAO of the Airline for operator==
bool Airline::operator==(const Airline& a) const {
  if (IATA_ != "" && a.IATA_ != "") return IATA_ == a.IATA_;
  return ICAO_ == a.ICAO_;
}

// Compares the IATA/ICAO of the Airline for operator<
bool Airline::operator<(const Airline& a) const {
  if (IATA_ != "" && a.IATA_ != "") return IATA_ < a.IATA_;
  return ICAO_ < a.ICAO_;
}

// Overloads << for easier output of the data
ostream& operator<<(ostream& out, const Airline& obj) {
  out << obj.ID_ << "," << obj.name_ << ",\\N," << obj.IATA_ << "," << obj.ICAO_
      << ",\\N," << obj.country_ << ",\"Y\"";
  return out;
}
