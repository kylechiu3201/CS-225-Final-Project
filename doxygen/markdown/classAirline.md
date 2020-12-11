::: {#classAirline}
:::

[\[classAirline\]]{#classAirline label="classAirline"}

class for the airline data.

\#include $<$airline.h$>$

()

*Constructor for default object.*

(int ID, std::string name, std::string IATA, std::string ICAO,
std::string country)

*Constructor for object with the given parameters.*

int ()

*Gets the ID of the airline.*

std::string () const

*Gets the name of the airline.*

std::string () const

*Gets the IATA code of the airline.*

std::string () const

*Gets the ICAO code of the airline.*

std::string () const

*Gets the country of the airline.*

bool (const &a) const

*Compares if the current airline $>$ the chosen airline.*

bool (const &a) const

*Compares if the current airline $<$ the chosen airline.*

bool (const &a) const

*Compares if the current airline == the chosen airline.*

ostream & (ostream &out, const &obj)

*Formats data for easier output.*

class for the airline data.

Constructor for object with the given parameters.

Parameters *ID* & The ID of the airline\
& The name of the airline\
& The IATA code of the airline\
& The ICAO code of the airline\
& The country of the airline\

Gets the country of the airline.

Returns The country of the airline

Gets the IATA code of the airline.

Returns The IATA code of the airline

Gets the ICAO code of the airline.

Returns The ICAO code of the airline

Gets the ID of the airline.

Returns The ID of the airline

Gets the name of the airline.

Returns The name of the airline

Compares if the current airline $<$ the chosen airline.

Parameters *a* & The chosen airline\

Returns If the current airline $<$ the chosen airline

Compares if the current airline == the chosen airline.

Parameters *a* & The chosen airline\

Returns If the current airline == the chosen airline

Compares if the current airline $>$ the chosen airline.

Parameters *a* & The chosen airline\

Returns If the current airline $>$ the chosen airline

Formats data for easier output.

Parameters *out* & The stream to output to\
& The object to output\

Returns The outputted stream

The documentation for this class was generated from the following file:

airline/airline.h
