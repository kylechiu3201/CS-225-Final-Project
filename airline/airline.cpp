#include "airline.h"

Airline::Airline() {}
Airline::Airline(int ID, std::string name, std::string IATA, std::string ICAO,
                 std::string country) {
  ID_ = ID;
  name_ = name;
  IATA_ = IATA;
  ICAO_ = ICAO;
  country_ = country;
}

int Airline::get_ID() { return ID_; }

std::string Airline::get_name() const { return name_; }

std::string Airline::get_IATA() const { return IATA_; }

std::string Airline::get_ICAO() const { return ICAO_; }

std::string Airline::get_country() const { return country_; }

/* bool Airline::operator>(const Airline& a) const { return ID_ > a.ID_; } */

bool Airline::operator>(const Airline& a) const {
  if(IATA_ != "" && a.IATA_ != "")
    return IATA_ > a.IATA_;
  return ICAO_ > a.ICAO_;
}

bool Airline::operator==(const Airline& a) const {
  if(IATA_ != "" && a.IATA_ != "")
    return IATA_ == a.IATA_;
  return ICAO_ == a.ICAO_;
}

/* bool Airline::operator<(const Airline& a) const { return ID_ < a.ID_; } */

bool Airline::operator<(const Airline& a) const {
  if(IATA_ != "" && a.IATA_ != "")
    return IATA_ < a.IATA_;
  return ICAO_ < a.ICAO_;
}

ostream& operator<<(ostream& out, const Airline& obj) {
  out << obj.ID_ << "," << obj.name_ << ",\\N," << obj.IATA_ << "," << obj.ICAO_ << ",\\N," << obj.country_ << ",\"Y\"";
  return out;
}
