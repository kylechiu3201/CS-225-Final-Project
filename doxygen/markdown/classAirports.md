::: {#classAirports}
:::

[\[classAirports\]]{#classAirports label="classAirports"}

class with graph algorithms for the graph of the airport and route data.

\#include $<$airports.h$>$

struct

(std::string filename, std::string fileair, std::string fileroute)

*Creates an object with the given parameters.*

void ( v, vector$<$ $>$ &path)

*Helper function for*

vector$<$ vector$<$ $>$ $>$ ()

*Performs a breadth first search on the graph.*

void (vector$<$ vector$<$ $>$$>$ v)

*Exports the breadth first search to a text file.*

vector$<$ $>$ (std::string B)

*Gets the shortest path from one airport to another.*

long double (std::string B)

*Gets the shortest distance from one airport to another.*

vector$<$ int $>$ (std::string A)

*Sets up Dijkstras algorithm.*

void (std::string B)

*Exports the shortest path data to a text file.*

& ()

*Gets the current airport graph.*

vector$<$ $>$ ()

*Gets all vertices in the airport graph.*

vector$<$ $>$ ()

*Gets all edges in the airport graph.*

unordered\_map$<$ int, $>$ ()

*Gets the map from IDs to objects.*

unordered\_map$<$ std::string, $>$ ()

*Gets the map from IATA/ICAO to objects.*

std::string (std::string airline)

*Gets a chosen/all airlines for strongly connected components with an
in-degree of zero.*

std::vector$<$ std::vector$<$ $>$ $>$ (std::string airline)

*Gets the strongly connected components with an in-degree of zero of the
given airline.*

std::string (map$<$ , vector$<$ vector$<$ $>$$>$$>$ scc)

*Exports the strongly connected data to a text file.*

class with graph algorithms for the graph of the airport and route data.

Creates an object with the given parameters.

Parameters *filename* & The path of the file for airport data\
& The path of the file for airline data\
& The path of the file for route data\

Gets a chosen/all airlines for strongly connected components with an
in-degree of zero.

Parameters *airline* & Either the IATA/ICAO of the chosen airline or an
string that indicates that the user wants all airlines\

Returns The name of the file with the exported data

Performs a breadth first search on the graph.

Returns The vector of the breadth first search

Helper function for

Parameters *v* & The current Vertex\
& The path of the search\

Exports the breadth first search to a text file.

Parameters *v* & The breadth first search vector\

Sets up Dijkstras algorithm.

Parameters *A* & The name of the starting airport\

Returns The vector of the airport IDs

Exports the strongly connected data to a text file.

Parameters *scc* & A map of Airlines to its respective vector of
strongly connected components\

Returns The name of the file with the exported data

Gets the current airport graph.

Returns The current airport graph

Gets the map from IDs to objects.

Returns The map from IDs to objects

Gets the map from IATA/ICAO to objects.

Returns The map from IATA/ICAO to objects

Gets all edges in the airport graph.

Returns The vector of all edges in the airport graph

Gets the strongly connected components with an in-degree of zero of the
given airline.

Parameters *airline* & The IATA/ICAO of the chosen airline\

Returns The vector of the strongly connected components with an
in-degree of zero

Gets all vertices in the airport graph.

Returns The vector of all vertices in the airport graph

Gets the shortest distance from one airport to another.

Parameters *B* & The name of the airport\

Returns The distance from one airport to another

Gets the shortest path from one airport to another.

Parameters *B* & The name of the airport\

Returns The vector of the vertices in the path

Exports the shortest path data to a text file.

Parameters *B* & The name of the airport\

The documentation for this class was generated from the following file:

airports/airports.h
