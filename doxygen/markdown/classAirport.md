::: {#classAirport}
:::

[\[classAirport\]]{#classAirport label="classAirport"}

class for airport data.

\#include $<$airport.h$>$

()

*Constructor for default object.*

(int port, string name, string city, string country, string IATA, string
ICAO, long double latitude, long double longitude)

*Constructor for object with given parameters.*

int () const

*Gets the ID of the airport.*

string () const

*Gets the name of the airport.*

string () const

*Gets the city of the airport.*

string () const

*Gets the country of the airport.*

string () const

*Gets the IATA code of the airport.*

string () const

*Gets the ICAO code of the airport.*

long double () const

*Gets the latitude coordinate of the airport.*

long double () const

*Gets the longitude coordinate of the airport.*

string () const

*Gets the label of the airport.*

void (long double latitude)

*Sets the latitude coordinate of the airport.*

void (long double longitude)

*Sets the longitude coordinate of the airport.*

void (string l)

*Sets the label of the airport.*

bool (const &a) const

*Compares if the current airport $<$ the chosen airport.*

bool (const &a) const

*Compares if the current airport $>$ the chosen airport.*

bool (const &a) const

*Compares if the current airport == the chosen airport.*

bool (const &a) const

*Compares if the current airport != the chosen airport.*

static long double (const &a, const &b, char units)

*Gets the distance from one airport to another.*

ostream & (ostream &out, const &obj)

*Formats output of data for easier outputting.*

class for airport data.

Constructor for object with given parameters.

Parameters *port* & The ID of the airport\
& The name of the airport\
& The city of the airport\
& The country of the airport\
& The IATA code of the airport\
& The ICAO code of the airport\
& The latitude coordinate of the airport\
& The longitude coordinate of the airport\

Gets the city of the airport.

Returns The city of the airport

Gets the country of the airport.

Returns The country of the airport

Gets the distance from one airport to another.

Parameters *a* & The first airport\
& The second airport\
& The units of the distance\

Returns The distance from one airport to another

Gets the IATA code of the airport.

Returns The IATA code of the airport

Gets the ICAO code of the airport.

Returns The ICAO code of the airport

Gets the label of the airport.

Returns The label of the airport

Gets the latitude coordinate of the airport.

Returns The latitude coordinate of the airport

Gets the longitude coordinate of the airport.

Returns The longitude coordinate of the airport

Gets the name of the airport.

Returns The name of the airport

Gets the ID of the airport.

Returns The ID of the airport

Compares if the current airport != the chosen airport.

Parameters *a* & The chosen airport to compare to\

Returns If the current airport != the chosen airport

Compares if the current airport $<$ the chosen airport.

Parameters *a* & The chosen airport to compare to\

Returns If the current airport $<$ the chosen airport

Compares if the current airport == the chosen airport.

Parameters *a* & The chosen airport to compare to\

Returns If the current airport == the chosen airport

Compares if the current airport $>$ the chosen airport.

Parameters *a* & The chosen airport to compare to\

Returns If the current airport $>$ the chosen airport

Sets the label of the airport.

Parameters *l* & The label of the airport\

Sets the latitude coordinate of the airport.

Parameters *latitude* & The latitude coordinate of the airport\

Sets the longitude coordinate of the airport.

Parameters *longitude* & The longitude coordinate of the airport\

Formats output of data for easier outputting.

Parameters *out* & The stream to output to\
& The object to output\

Returns The outputted stream

The documentation for this class was generated from the following file:

airport/airport.h
