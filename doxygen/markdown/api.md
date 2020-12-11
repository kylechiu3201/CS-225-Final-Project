# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Airline`](#classAirline) | [Airline](#classAirline) class for the airline data.
`class `[`Airport`](#classAirport) | [Airport](#classAirport) class for airport data.
`class `[`Airports`](#classAirports) | [Airports](#classAirports) class with graph algorithms for the graph of the airport and route data.
`class `[`Edge`](#classEdge) | Represents an edge in a graph; used by the [Graph](#classGraph) class.
`class `[`Graph`](#classGraph) | Represents a graph; used by the GraphTools class.
`struct `[`Airports::dijkstras_graph`](#structAirports_1_1dijkstras__graph) | 

# class `Airline` 

[Airline](#classAirline) class for the airline data.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Airline`](#classAirline_1a2e6766b5e3a4e3106062c710740a2a32)`()` | Constructor for default [Airline](#classAirline) object.
`public  `[`Airline`](#classAirline_1a1da96883543850e32dcc33448a780fc2)`(int ID,std::string name,std::string IATA,std::string ICAO,std::string country)` | Constructor for [Airline](#classAirline) object with the given parameters.
`public int `[`get_ID`](#classAirline_1a30886eeae1e57b8644a767df166fdca3)`()` | Gets the ID of the airline.
`public std::string `[`get_name`](#classAirline_1aea0fccfd6050bcce23ae36034ab5de9d)`() const` | Gets the name of the airline.
`public std::string `[`get_IATA`](#classAirline_1a25a2e59a6f91694b09b4d0bd330da8d6)`() const` | Gets the IATA code of the airline.
`public std::string `[`get_ICAO`](#classAirline_1a74b819156a01f55fe9d49c86cf2f37ab)`() const` | Gets the ICAO code of the airline.
`public std::string `[`get_country`](#classAirline_1abb870fe3dedfd9b98dda5c8785411d4d)`() const` | Gets the country of the airline.
`public bool `[`operator>`](#classAirline_1acd8da01493f52feb651b6368eced7e43)`(const `[`Airline`](#classAirline)` & a) const` | Compares if the current airline > the chosen airline.
`public bool `[`operator<`](#classAirline_1accd359188347ebdd03b1f8366e772e66)`(const `[`Airline`](#classAirline)` & a) const` | Compares if the current airline < the chosen airline.
`public bool `[`operator==`](#classAirline_1a83d780dc61f34056b2854c988aeb6ae9)`(const `[`Airline`](#classAirline)` & a) const` | Compares if the current airline == the chosen airline.

## Members

#### `public  `[`Airline`](#classAirline_1a2e6766b5e3a4e3106062c710740a2a32)`()` 

Constructor for default [Airline](#classAirline) object.

#### `public  `[`Airline`](#classAirline_1a1da96883543850e32dcc33448a780fc2)`(int ID,std::string name,std::string IATA,std::string ICAO,std::string country)` 

Constructor for [Airline](#classAirline) object with the given parameters.

#### Parameters
* `ID` The ID of the airline 

* `name` The name of the airline 

* `IATA` The IATA code of the airline 

* `ICAO` The ICAO code of the airline 

* `country` The country of the airline

#### `public int `[`get_ID`](#classAirline_1a30886eeae1e57b8644a767df166fdca3)`()` 

Gets the ID of the airline.

#### Returns
The ID of the airline

#### `public std::string `[`get_name`](#classAirline_1aea0fccfd6050bcce23ae36034ab5de9d)`() const` 

Gets the name of the airline.

#### Returns
The name of the airline

#### `public std::string `[`get_IATA`](#classAirline_1a25a2e59a6f91694b09b4d0bd330da8d6)`() const` 

Gets the IATA code of the airline.

#### Returns
The IATA code of the airline

#### `public std::string `[`get_ICAO`](#classAirline_1a74b819156a01f55fe9d49c86cf2f37ab)`() const` 

Gets the ICAO code of the airline.

#### Returns
The ICAO code of the airline

#### `public std::string `[`get_country`](#classAirline_1abb870fe3dedfd9b98dda5c8785411d4d)`() const` 

Gets the country of the airline.

#### Returns
The country of the airline

#### `public bool `[`operator>`](#classAirline_1acd8da01493f52feb651b6368eced7e43)`(const `[`Airline`](#classAirline)` & a) const` 

Compares if the current airline > the chosen airline.

#### Parameters
* `a` The chosen airline

#### Returns
If the current airline > the chosen airline

#### `public bool `[`operator<`](#classAirline_1accd359188347ebdd03b1f8366e772e66)`(const `[`Airline`](#classAirline)` & a) const` 

Compares if the current airline < the chosen airline.

#### Parameters
* `a` The chosen airline

#### Returns
If the current airline < the chosen airline

#### `public bool `[`operator==`](#classAirline_1a83d780dc61f34056b2854c988aeb6ae9)`(const `[`Airline`](#classAirline)` & a) const` 

Compares if the current airline == the chosen airline.

#### Parameters
* `a` The chosen airline

#### Returns
If the current airline == the chosen airline

# class `Airport` 

[Airport](#classAirport) class for airport data.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Airport`](#classAirport_1a2fc0f2402c94225b9deaf76176bb887f)`()` | Constructor for default [Airport](#classAirport) object.
`public  `[`Airport`](#classAirport_1a0bd7ed332d90fee37935549eec68ad79)`(int port,string name,string city,string country,string IATA,string ICAO,long double latitude,long double longitude)` | Constructor for [Airport](#classAirport) object with given parameters.
`public int `[`get_port_ID`](#classAirport_1a716f2c1f73af5ff8db9fca930a134b8a)`() const` | Gets the ID of the airport.
`public string `[`get_name`](#classAirport_1aba2a885b9234bc88b099693ab99a4b5e)`() const` | Gets the name of the airport.
`public string `[`get_city`](#classAirport_1ad2b9493144e3f909a0f400c658bc9ce1)`() const` | Gets the city of the airport.
`public string `[`get_country`](#classAirport_1a5828a1a9e3fb731634de4aa67aaa4142)`() const` | Gets the country of the airport.
`public string `[`get_IATA`](#classAirport_1ac33fe90defa1fe4a6ecbe85d1f99dcab)`() const` | Gets the IATA code of the airport.
`public string `[`get_ICAO`](#classAirport_1a2fc94e41895ecbe8baadefcc8705c5cc)`() const` | Gets the ICAO code of the airport.
`public long double `[`get_latitude`](#classAirport_1ae3905ae188a1541bf5896ff3369b264b)`() const` | Gets the latitude coordinate of the airport.
`public long double `[`get_longitude`](#classAirport_1a8302cfc337f85b471eb5e52a463cb9d4)`() const` | Gets the longitude coordinate of the airport.
`public string `[`get_label`](#classAirport_1aaa5fc48bf61a4321fc69ca493a5e0c2d)`() const` | Gets the label of the airport.
`public void `[`set_lat`](#classAirport_1ae661f2cf8fd4a7d4e2861e5f5501955e)`(long double latitude)` | Sets the latitude coordinate of the airport.
`public void `[`set_long`](#classAirport_1a1b9a004a4e9bdd4bac43fd82ac8ccef1)`(long double longitude)` | Sets the longitude coordinate of the airport.
`public void `[`set_label`](#classAirport_1a603cbcce9a09c5f1c55ef546d9d3496d)`(string l)` | Sets the label of the airport.
`public bool `[`operator<`](#classAirport_1aafe7d46ae6228fd2614054ec0ba391a8)`(const `[`Airport`](#classAirport)` & a) const` | Compares if the current airport < the chosen airport.
`public bool `[`operator>`](#classAirport_1a2181b5de9ec0ed9ec191c315602fd96a)`(const `[`Airport`](#classAirport)` & a) const` | Compares if the current airport > the chosen airport.
`public bool `[`operator==`](#classAirport_1a56e32d1259b6771e91573b7bbb5a7228)`(const `[`Airport`](#classAirport)` & a) const` | Compares if the current airport == the chosen airport.
`public bool `[`operator!=`](#classAirport_1a1e904d80768de9a62f42ca7b1d099716)`(const `[`Airport`](#classAirport)` & a) const` | Compares if the current airport != the chosen airport.

## Members

#### `public  `[`Airport`](#classAirport_1a2fc0f2402c94225b9deaf76176bb887f)`()` 

Constructor for default [Airport](#classAirport) object.

#### `public  `[`Airport`](#classAirport_1a0bd7ed332d90fee37935549eec68ad79)`(int port,string name,string city,string country,string IATA,string ICAO,long double latitude,long double longitude)` 

Constructor for [Airport](#classAirport) object with given parameters.

#### Parameters
* `port` The ID of the airport 

* `name` The name of the airport 

* `city` The city of the airport 

* `country` The country of the airport 

* `IATA` The IATA code of the airport 

* `ICAO` The ICAO code of the airport 

* `latitude` The latitude coordinate of the airport 

* `longitude` The longitude coordinate of the airport

#### `public int `[`get_port_ID`](#classAirport_1a716f2c1f73af5ff8db9fca930a134b8a)`() const` 

Gets the ID of the airport.

#### Returns
The ID of the airport

#### `public string `[`get_name`](#classAirport_1aba2a885b9234bc88b099693ab99a4b5e)`() const` 

Gets the name of the airport.

#### Returns
The name of the airport

#### `public string `[`get_city`](#classAirport_1ad2b9493144e3f909a0f400c658bc9ce1)`() const` 

Gets the city of the airport.

#### Returns
The city of the airport

#### `public string `[`get_country`](#classAirport_1a5828a1a9e3fb731634de4aa67aaa4142)`() const` 

Gets the country of the airport.

#### Returns
The country of the airport

#### `public string `[`get_IATA`](#classAirport_1ac33fe90defa1fe4a6ecbe85d1f99dcab)`() const` 

Gets the IATA code of the airport.

#### Returns
The IATA code of the airport

#### `public string `[`get_ICAO`](#classAirport_1a2fc94e41895ecbe8baadefcc8705c5cc)`() const` 

Gets the ICAO code of the airport.

#### Returns
The ICAO code of the airport

#### `public long double `[`get_latitude`](#classAirport_1ae3905ae188a1541bf5896ff3369b264b)`() const` 

Gets the latitude coordinate of the airport.

#### Returns
The latitude coordinate of the airport

#### `public long double `[`get_longitude`](#classAirport_1a8302cfc337f85b471eb5e52a463cb9d4)`() const` 

Gets the longitude coordinate of the airport.

#### Returns
The longitude coordinate of the airport

#### `public string `[`get_label`](#classAirport_1aaa5fc48bf61a4321fc69ca493a5e0c2d)`() const` 

Gets the label of the airport.

#### Returns
The label of the airport

#### `public void `[`set_lat`](#classAirport_1ae661f2cf8fd4a7d4e2861e5f5501955e)`(long double latitude)` 

Sets the latitude coordinate of the airport.

#### Parameters
* `latitude` The latitude coordinate of the airport

#### `public void `[`set_long`](#classAirport_1a1b9a004a4e9bdd4bac43fd82ac8ccef1)`(long double longitude)` 

Sets the longitude coordinate of the airport.

#### Parameters
* `longitude` The longitude coordinate of the airport

#### `public void `[`set_label`](#classAirport_1a603cbcce9a09c5f1c55ef546d9d3496d)`(string l)` 

Sets the label of the airport.

#### Parameters
* `l` The label of the airport

#### `public bool `[`operator<`](#classAirport_1aafe7d46ae6228fd2614054ec0ba391a8)`(const `[`Airport`](#classAirport)` & a) const` 

Compares if the current airport < the chosen airport.

#### Parameters
* `a` The chosen airport to compare to

#### Returns
If the current airport < the chosen airport

#### `public bool `[`operator>`](#classAirport_1a2181b5de9ec0ed9ec191c315602fd96a)`(const `[`Airport`](#classAirport)` & a) const` 

Compares if the current airport > the chosen airport.

#### Parameters
* `a` The chosen airport to compare to

#### Returns
If the current airport > the chosen airport

#### `public bool `[`operator==`](#classAirport_1a56e32d1259b6771e91573b7bbb5a7228)`(const `[`Airport`](#classAirport)` & a) const` 

Compares if the current airport == the chosen airport.

#### Parameters
* `a` The chosen airport to compare to

#### Returns
If the current airport == the chosen airport

#### `public bool `[`operator!=`](#classAirport_1a1e904d80768de9a62f42ca7b1d099716)`(const `[`Airport`](#classAirport)` & a) const` 

Compares if the current airport != the chosen airport.

#### Parameters
* `a` The chosen airport to compare to

#### Returns
If the current airport != the chosen airport

# class `Airports` 

[Airports](#classAirports) class with graph algorithms for the graph of the airport and route data.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Airports`](#classAirports_1acddd4e0844de9718621bcb65c2bbd923)`(std::string filename,std::string fileair,std::string fileroute)` | Creates an [Airports](#classAirports) object with the given parameters.
`public void `[`bfs`](#classAirports_1ad9aeeb8a73d5c121e66aeec55211e44c)`(`[`Vertex`](#classAirport)` v,vector< `[`Vertex`](#classAirport)` > & path)` | Helper function for [bfs()](#classAirports_1a4c7801db9d9d030694896b7ace7e4d62)
`public vector< vector< `[`Vertex`](#classAirport)` > > `[`bfs`](#classAirports_1a4c7801db9d9d030694896b7ace7e4d62)`()` | Performs a breadth first search on the [Airport](#classAirport) graph.
`public void `[`bfs_to_text`](#classAirports_1ab64e235519e96fbfd58ae6045f088b0f)`(vector< vector< `[`Vertex`](#classAirport)` >> v)` | Exports the breadth first search to a text file.
`public vector< `[`Airport`](#classAirport)` > `[`shortest_path`](#classAirports_1a6ab5d68cc26c5b201000fc20d8f08679)`(std::string B)` | Gets the shortest path from one airport to another.
`public long double `[`shortest_dist`](#classAirports_1a65496328754ac42865e74d3ae5e75e57)`(std::string B)` | Gets the shortest distance from one airport to another.
`public vector< int > `[`create_dijkstras`](#classAirports_1a598a4a8033e662d576043e0fa1b461ea)`(std::string A)` | Sets up Dijkstra's algorithm.
`public void `[`shortest_to_text`](#classAirports_1aa2e942d705f14dd5d43161977de8a17f)`(std::string B)` | Exports the shortest path data to a text file.
`public `[`Graph`](#classGraph)` & `[`get_graph`](#classAirports_1a09e694ebcac791327c5969d744359bb0)`()` | Gets the current airport graph.
`public vector< `[`Vertex`](#classAirport)` > `[`getVertices`](#classAirports_1a2a336ca779e3c392aab21a9837d5223b)`()` | Gets all vertices in the airport graph.
`public vector< `[`Edge`](#classEdge)` > `[`getEdges`](#classAirports_1a03f8769b03be0ad9e3d86b7e2e363904)`()` | Gets all edges in the airport graph.
`public unordered_map< int, `[`Airport`](#classAirport)` > `[`get_id_map`](#classAirports_1a048b54cb44483f4829f67d236d0509e6)`()` | Gets the map from IDs to [Airport](#classAirport) objects.
`public unordered_map< std::string, `[`Airport`](#classAirport)` > `[`get_port_map`](#classAirports_1a7129e22c60acf8b8e79da7eef9959886)`()` | Gets the map from IATA/ICAO to [Airport](#classAirport) objects.
`public std::string `[`airlinesAdded`](#classAirports_1a3aad12a8519830591aaf6cb6311ca4bc)`(std::string airline)` | Gets a chosen/all airlines for strongly connected components with an in-degree of zero.
`public std::vector< std::vector< `[`Vertex`](#classAirport)` > > `[`getStronglyConnected`](#classAirports_1a1e6394edcd3de2004e3b4b60cbebb434)`(std::string airline)` | Gets the strongly connected components with an in-degree of zero of the given airline.
`public std::string `[`exportStronglyConnected`](#classAirports_1aa51338d2d41bc643c2e1a6c7dfd34b0d)`(map< `[`Airline](#classAirline), vector< vector< [Vertex`](#classAirport)` >>> scc)` | Exports the strongly connected data to a text file.

## Members

#### `public  `[`Airports`](#classAirports_1acddd4e0844de9718621bcb65c2bbd923)`(std::string filename,std::string fileair,std::string fileroute)` 

Creates an [Airports](#classAirports) object with the given parameters.

#### Parameters
* `filename` The path of the file for airport data 

* `fileair` The path of the file for airline data 

* `fileroute` The path of the file for route data

#### `public void `[`bfs`](#classAirports_1ad9aeeb8a73d5c121e66aeec55211e44c)`(`[`Vertex`](#classAirport)` v,vector< `[`Vertex`](#classAirport)` > & path)` 

Helper function for [bfs()](#classAirports_1a4c7801db9d9d030694896b7ace7e4d62)

#### Parameters
* `v` The current Vertex 

* `path` The path of the search

#### `public vector< vector< `[`Vertex`](#classAirport)` > > `[`bfs`](#classAirports_1a4c7801db9d9d030694896b7ace7e4d62)`()` 

Performs a breadth first search on the [Airport](#classAirport) graph.

#### Returns
The vector of the breadth first search

#### `public void `[`bfs_to_text`](#classAirports_1ab64e235519e96fbfd58ae6045f088b0f)`(vector< vector< `[`Vertex`](#classAirport)` >> v)` 

Exports the breadth first search to a text file.

#### Parameters
* `v` The breadth first search vector

#### `public vector< `[`Airport`](#classAirport)` > `[`shortest_path`](#classAirports_1a6ab5d68cc26c5b201000fc20d8f08679)`(std::string B)` 

Gets the shortest path from one airport to another.

#### Parameters
* `B` The name of the airport

#### Returns
The vector of the vertices in the path

#### `public long double `[`shortest_dist`](#classAirports_1a65496328754ac42865e74d3ae5e75e57)`(std::string B)` 

Gets the shortest distance from one airport to another.

#### Parameters
* `B` The name of the airport

#### Returns
The distance from one airport to another

#### `public vector< int > `[`create_dijkstras`](#classAirports_1a598a4a8033e662d576043e0fa1b461ea)`(std::string A)` 

Sets up Dijkstra's algorithm.

#### Parameters
* `A` The name of the starting airport

#### Returns
The vector of the airport IDs

#### `public void `[`shortest_to_text`](#classAirports_1aa2e942d705f14dd5d43161977de8a17f)`(std::string B)` 

Exports the shortest path data to a text file.

#### Parameters
* `B` The name of the airport

#### `public `[`Graph`](#classGraph)` & `[`get_graph`](#classAirports_1a09e694ebcac791327c5969d744359bb0)`()` 

Gets the current airport graph.

#### Returns
The current airport graph

#### `public vector< `[`Vertex`](#classAirport)` > `[`getVertices`](#classAirports_1a2a336ca779e3c392aab21a9837d5223b)`()` 

Gets all vertices in the airport graph.

#### Returns
The vector of all vertices in the airport graph

#### `public vector< `[`Edge`](#classEdge)` > `[`getEdges`](#classAirports_1a03f8769b03be0ad9e3d86b7e2e363904)`()` 

Gets all edges in the airport graph.

#### Returns
The vector of all edges in the airport graph

#### `public unordered_map< int, `[`Airport`](#classAirport)` > `[`get_id_map`](#classAirports_1a048b54cb44483f4829f67d236d0509e6)`()` 

Gets the map from IDs to [Airport](#classAirport) objects.

#### Returns
The map from IDs to [Airport](#classAirport) objects

#### `public unordered_map< std::string, `[`Airport`](#classAirport)` > `[`get_port_map`](#classAirports_1a7129e22c60acf8b8e79da7eef9959886)`()` 

Gets the map from IATA/ICAO to [Airport](#classAirport) objects.

#### Returns
The map from IATA/ICAO to [Airport](#classAirport) objects

#### `public std::string `[`airlinesAdded`](#classAirports_1a3aad12a8519830591aaf6cb6311ca4bc)`(std::string airline)` 

Gets a chosen/all airlines for strongly connected components with an in-degree of zero.

#### Parameters
* `airline` Either the IATA/ICAO of the chosen airline or an string that indicates that the user wants all airlines

#### Returns
The name of the file with the exported data

#### `public std::vector< std::vector< `[`Vertex`](#classAirport)` > > `[`getStronglyConnected`](#classAirports_1a1e6394edcd3de2004e3b4b60cbebb434)`(std::string airline)` 

Gets the strongly connected components with an in-degree of zero of the given airline.

#### Parameters
* `airline` The IATA/ICAO of the chosen airline

#### Returns
The vector of the strongly connected components with an in-degree of zero

#### `public std::string `[`exportStronglyConnected`](#classAirports_1aa51338d2d41bc643c2e1a6c7dfd34b0d)`(map< `[`Airline](#classAirline), vector< vector< [Vertex`](#classAirport)` >>> scc)` 

Exports the strongly connected data to a text file.

#### Parameters
* `scc` A map of Airlines to its respective vector of strongly connected components

#### Returns
The name of the file with the exported data

# class `Edge` 

Represents an edge in a graph; used by the [Graph](#classGraph) class.

Sean Massung 

Spring 2012

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`Vertex`](#classAirport)` `[`source`](#classEdge_1a7d414269470d1b77d53d2cfef70056ca) | The source of the edge
`public `[`Vertex`](#classAirport)` `[`dest`](#classEdge_1ae8dbce3b105457b6b394e4d7e3d60a44) | The destination of the edge
`public inline  `[`Edge`](#classEdge_1aa14f406ba9fce62efb9eed7e89d1d9d5)`(`[`Vertex`](#classAirport)` u,`[`Vertex`](#classAirport)` v)` | Parameter constructor for unweighted graphs. 
`public inline  `[`Edge`](#classEdge_1a94686ecfbf52d3c38976e5f5ead3e006)`(`[`Vertex`](#classAirport)` u,`[`Vertex`](#classAirport)` v,string lbl)` | Parameter constructor for unweighted graphs. 
`public inline  `[`Edge`](#classEdge_1abe8c647873a2b98378a7edaf5d23ea26)`(`[`Vertex`](#classAirport)` u,`[`Vertex`](#classAirport)` v,double w,string lbl)` | Parameter constructor for weighted graphs. 
`public inline  `[`Edge`](#classEdge_1a3106b11d60125009dbf7a738ce540fdf)`()` | Default constructor.
`public inline bool `[`operator<`](#classEdge_1ab6a06c5da57efed1991960f61e870c8b)`(const `[`Edge`](#classEdge)` & other) const` | Compares two Edges. operator< is defined so Edges can be sorted with std::sort. 
`public inline string `[`getLabel`](#classEdge_1a7aaf5a50c5768e06015e60e3f0bbbec3)`() const` | Gets edge label.
`public inline double `[`getWeight`](#classEdge_1a1caaffca117bab3ff5b7387623a356f8)`() const` | Gets edge weight.
`public inline bool `[`operator==`](#classEdge_1a8aac4dd9e059b08f912a55e4088fa997)`(`[`Edge`](#classEdge)` & other) const` | Compares two edges' source and dest. 

## Members

#### `public `[`Vertex`](#classAirport)` `[`source`](#classEdge_1a7d414269470d1b77d53d2cfef70056ca) 

The source of the edge

#### `public `[`Vertex`](#classAirport)` `[`dest`](#classEdge_1ae8dbce3b105457b6b394e4d7e3d60a44) 

The destination of the edge

#### `public inline  `[`Edge`](#classEdge_1aa14f406ba9fce62efb9eed7e89d1d9d5)`(`[`Vertex`](#classAirport)` u,`[`Vertex`](#classAirport)` v)` 

Parameter constructor for unweighted graphs. 
#### Parameters
* `u` - one vertex the edge is connected to 

* `v` - the other vertex it is connected to

#### `public inline  `[`Edge`](#classEdge_1a94686ecfbf52d3c38976e5f5ead3e006)`(`[`Vertex`](#classAirport)` u,`[`Vertex`](#classAirport)` v,string lbl)` 

Parameter constructor for unweighted graphs. 
#### Parameters
* `u` - one vertex the edge is connected to 

* `v` - the other vertex it is connected to 

* `lbl` - the edge label

#### `public inline  `[`Edge`](#classEdge_1abe8c647873a2b98378a7edaf5d23ea26)`(`[`Vertex`](#classAirport)` u,`[`Vertex`](#classAirport)` v,double w,string lbl)` 

Parameter constructor for weighted graphs. 
#### Parameters
* `u` - one vertex the edge is connected to 

* `v` - the other vertex it is connected to 

* `w` - the weight of the edge 

* `lbl` - the edge label

#### `public inline  `[`Edge`](#classEdge_1a3106b11d60125009dbf7a738ce540fdf)`()` 

Default constructor.

#### `public inline bool `[`operator<`](#classEdge_1ab6a06c5da57efed1991960f61e870c8b)`(const `[`Edge`](#classEdge)` & other) const` 

Compares two Edges. operator< is defined so Edges can be sorted with std::sort. 
#### Parameters
* `other` - the edge to compare with 

#### Returns
whether the current edge is less than the parameter

#### `public inline string `[`getLabel`](#classEdge_1a7aaf5a50c5768e06015e60e3f0bbbec3)`() const` 

Gets edge label.

#### `public inline double `[`getWeight`](#classEdge_1a1caaffca117bab3ff5b7387623a356f8)`() const` 

Gets edge weight.

#### `public inline bool `[`operator==`](#classEdge_1a8aac4dd9e059b08f912a55e4088fa997)`(`[`Edge`](#classEdge)` & other) const` 

Compares two edges' source and dest. 
#### Parameters
* `other` - the edge to compare with

# class `Graph` 

Represents a graph; used by the GraphTools class.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Graph`](#classGraph_1ae4c72b8ac4d693c49800a4c7e273654f)`()` | Constructor to create an empty directed and weighted graph.
`public  `[`Graph`](#classGraph_1a62fa04782e9a454208a4c69bc2bdaca1)`(bool weighted)` | Constructor to create an empty graph. 
`public  `[`Graph`](#classGraph_1a136bab2fe6248f5ac581938c22f2ad17)`(bool weighted,bool directed)` | Constructor to create an empty graph. 
`public  `[`Graph`](#classGraph_1aeee217470dc6c4ce91f71cd017770f29)`(bool weighted,int numVertices,unsigned long seed)` | Constructor to create a random, connected graph. 
`public vector< `[`Vertex`](#classAirport)` > `[`getAdjacent`](#classGraph_1a17a74ca643a8bd9d3bb3e9fc5d8a81d5)`(`[`Vertex`](#classAirport)` source) const` | Gets all adjacent vertices to the parameter vertex. 
`public `[`Vertex`](#classAirport)` `[`getStartingVertex`](#classGraph_1a6a719a980479a4f280d56b0d3e86fc18)`() const` | Returns one vertex in the graph. This function can be used to find a random vertex with which to start a traversal. 
`public vector< `[`Vertex`](#classAirport)` > `[`getVertices`](#classGraph_1ada82948700b5839ceae81531c9ea824e)`() const` | Gets all vertices in the graph. 
`public `[`Edge`](#classEdge)` `[`getEdge`](#classGraph_1a9b1b8a9ef2d1782becb5ce635743148c)`(`[`Vertex`](#classAirport)` source,`[`Vertex`](#classAirport)` destination) const` | Gets an edge between two vertices. 
`public vector< `[`Edge`](#classEdge)` > `[`getEdges`](#classGraph_1a25e79a5ed1c774b3125bd5fa2dd22c05)`() const` | Gets all the edges in the graph. 
`public bool `[`vertexExists`](#classGraph_1a05a5031308ed33f8c4c5d7783ea34f29)`(`[`Vertex`](#classAirport)` v) const` | Checks if the given vertex exists. 
`public bool `[`edgeExists`](#classGraph_1a5b74dfabe5cf651e9afc629ae1cd91ce)`(`[`Vertex`](#classAirport)` source,`[`Vertex`](#classAirport)` destination) const` | Checks if edge exists between two vertices exists. 
`public `[`Edge`](#classEdge)` `[`setEdgeLabel`](#classGraph_1ac660a1ab375eee3ca5a8818116908070)`(`[`Vertex`](#classAirport)` source,`[`Vertex`](#classAirport)` destination,string label)` | Sets the edge label of the edge between vertices u and v. 
`public string `[`getEdgeLabel`](#classGraph_1a96722d70b16b0ec75a6839a36d30bbfa)`(`[`Vertex`](#classAirport)` source,`[`Vertex`](#classAirport)` destination) const` | Gets the edge label of the edge between vertices u and v. 
`public double `[`getEdgeWeight`](#classGraph_1aa9f6f3f1ebd2852d83b9ec37e84bd286)`(`[`Vertex`](#classAirport)` source,`[`Vertex`](#classAirport)` destination) const` | Gets the weight of the edge between two vertices. 
`public void `[`insertVertex`](#classGraph_1acbad3e118939a8324e4b95a093b5a3ed)`(`[`Vertex`](#classAirport)` v)` | Inserts a new vertex into the graph and initializes its label as "". 
`public `[`Vertex`](#classAirport)` `[`removeVertex`](#classGraph_1a08ea88e388e6468ca359521aa3542c03)`(`[`Vertex`](#classAirport)` v)` | Removes a given vertex from the graph. 
`public bool `[`insertEdge`](#classGraph_1ac81b23f4a2a1bffe765765a623b22ade)`(`[`Vertex`](#classAirport)` source,`[`Vertex`](#classAirport)` destination,`[`Airline`](#classAirline)` airline)` | Inserts an edge between two vertices. A boolean is returned for use with the random graph generation. Hence, an error is not thrown when it fails to insert an edge. 
`public `[`Edge`](#classEdge)` `[`removeEdge`](#classGraph_1adac871ac0cafe8753d6b3b348b448c8f)`(`[`Vertex`](#classAirport)` source,`[`Vertex`](#classAirport)` destination)` | Removes the edge between two vertices. 
`public `[`Edge`](#classEdge)` `[`setEdgeWeight`](#classGraph_1a115b9d4bcb87fb93949819d4be350acd)`(`[`Vertex`](#classAirport)` source,`[`Vertex`](#classAirport)` destination,double weight)` | Sets the weight of the edge between two vertices. 
`public bool `[`isDirected`](#classGraph_1a08b970ecb424505f85c4f9d632b5ab01)`() const` | Checks if the graph is directed or not.
`public void `[`clear`](#classGraph_1ac6192a41101102ca8aa6acca607c84f3)`()` | Clears the graph data.
`public void `[`printGraph`](#classGraph_1a5ac05db53839e72af76cdb2bafe88b77)`()` | Prints the graph to std::cout.
`public map< `[`Vertex](#classAirport), map< [Vertex](#classAirport), [Edge`](#classEdge)` > > `[`getList`](#classGraph_1a65b4ec8b396ad94e2269d49482d97516)`()` | 

## Members

#### `public  `[`Graph`](#classGraph_1ae4c72b8ac4d693c49800a4c7e273654f)`()` 

Constructor to create an empty directed and weighted graph.

#### `public  `[`Graph`](#classGraph_1a62fa04782e9a454208a4c69bc2bdaca1)`(bool weighted)` 

Constructor to create an empty graph. 
#### Parameters
* `weighted` - specifies whether the graph is a weighted graph or not

#### `public  `[`Graph`](#classGraph_1a136bab2fe6248f5ac581938c22f2ad17)`(bool weighted,bool directed)` 

Constructor to create an empty graph. 
#### Parameters
* `weighted` - specifies whether the graph is a weighted graph or not 

* `directed` - specifies whether the graph is directed

#### `public  `[`Graph`](#classGraph_1aeee217470dc6c4ce91f71cd017770f29)`(bool weighted,int numVertices,unsigned long seed)` 

Constructor to create a random, connected graph. 
#### Parameters
* `weighted` - specifies whether the graph is a weighted graph or not 

* `numVertices` - the number of vertices the graph will have 

* `seed` - a random seed to create the graph with

#### `public vector< `[`Vertex`](#classAirport)` > `[`getAdjacent`](#classGraph_1a17a74ca643a8bd9d3bb3e9fc5d8a81d5)`(`[`Vertex`](#classAirport)` source) const` 

Gets all adjacent vertices to the parameter vertex. 
#### Parameters
* `source` - vertex to get neighbors from 

#### Returns
a vector of vertices

#### `public `[`Vertex`](#classAirport)` `[`getStartingVertex`](#classGraph_1a6a719a980479a4f280d56b0d3e86fc18)`() const` 

Returns one vertex in the graph. This function can be used to find a random vertex with which to start a traversal. 
#### Returns
a vertex from the graph

#### `public vector< `[`Vertex`](#classAirport)` > `[`getVertices`](#classGraph_1ada82948700b5839ceae81531c9ea824e)`() const` 

Gets all vertices in the graph. 
#### Returns
a vector of all vertices in the graph

#### `public `[`Edge`](#classEdge)` `[`getEdge`](#classGraph_1a9b1b8a9ef2d1782becb5ce635743148c)`(`[`Vertex`](#classAirport)` source,`[`Vertex`](#classAirport)` destination) const` 

Gets an edge between two vertices. 
#### Parameters
* `source` - one vertex the edge is connected to 

* `destination` - the other vertex the edge is connected to 

#### Returns
- if exist, return the corresponding edge

* if edge doesn't exist, return [Edge()](#classEdge)

#### `public vector< `[`Edge`](#classEdge)` > `[`getEdges`](#classGraph_1a25e79a5ed1c774b3125bd5fa2dd22c05)`() const` 

Gets all the edges in the graph. 
#### Returns
a vector of all the edges in the graph

#### `public bool `[`vertexExists`](#classGraph_1a05a5031308ed33f8c4c5d7783ea34f29)`(`[`Vertex`](#classAirport)` v) const` 

Checks if the given vertex exists. 
#### Returns
- if Vertex exists, true

* if Vertex doesn't exist, return false

#### `public bool `[`edgeExists`](#classGraph_1a5b74dfabe5cf651e9afc629ae1cd91ce)`(`[`Vertex`](#classAirport)` source,`[`Vertex`](#classAirport)` destination) const` 

Checks if edge exists between two vertices exists. 
#### Returns
- if [Edge](#classEdge) exists, true

* if [Edge](#classEdge) doesn't exist, return false

#### `public `[`Edge`](#classEdge)` `[`setEdgeLabel`](#classGraph_1ac660a1ab375eee3ca5a8818116908070)`(`[`Vertex`](#classAirport)` source,`[`Vertex`](#classAirport)` destination,string label)` 

Sets the edge label of the edge between vertices u and v. 
#### Parameters
* `source` - one vertex the edge is connected to 

* `destination` - the other vertex the edge is connected to 

#### Returns
- if edge exists, set the label to the corresponding edge(if not directed, set the reverse one too), return edge with new label

* if edge doesn't exist, return InvalidEdge

#### `public string `[`getEdgeLabel`](#classGraph_1a96722d70b16b0ec75a6839a36d30bbfa)`(`[`Vertex`](#classAirport)` source,`[`Vertex`](#classAirport)` destination) const` 

Gets the edge label of the edge between vertices u and v. 
#### Parameters
* `source` - one vertex the edge is connected to 

* `destination` - the other vertex the edge is connected to 

#### Returns
- if edge exists, return edge label

* if edge doesn't exist, return InvalidLabel

#### `public double `[`getEdgeWeight`](#classGraph_1aa9f6f3f1ebd2852d83b9ec37e84bd286)`(`[`Vertex`](#classAirport)` source,`[`Vertex`](#classAirport)` destination) const` 

Gets the weight of the edge between two vertices. 
#### Parameters
* `source` - one vertex the edge is connected to 

* `destination` - the other vertex the edge is connected to 

#### Returns
- if edge exists, return edge wright

* if doesn't, return InvalidWeight

#### `public void `[`insertVertex`](#classGraph_1acbad3e118939a8324e4b95a093b5a3ed)`(`[`Vertex`](#classAirport)` v)` 

Inserts a new vertex into the graph and initializes its label as "". 
#### Parameters
* `v` - the name for the vertex

#### `public `[`Vertex`](#classAirport)` `[`removeVertex`](#classGraph_1a08ea88e388e6468ca359521aa3542c03)`(`[`Vertex`](#classAirport)` v)` 

Removes a given vertex from the graph. 
#### Parameters
* `v` - the vertex to remove 

#### Returns
- if v exists, return v

* if not, return InvalidVertex;

#### `public bool `[`insertEdge`](#classGraph_1ac81b23f4a2a1bffe765765a623b22ade)`(`[`Vertex`](#classAirport)` source,`[`Vertex`](#classAirport)` destination,`[`Airline`](#classAirline)` airline)` 

Inserts an edge between two vertices. A boolean is returned for use with the random graph generation. Hence, an error is not thrown when it fails to insert an edge. 
#### Parameters
* `source` - one vertex the edge is connected to 

* `destination` - the other vertex the edge is connected to 

#### Returns
whether inserting the edge was successful

#### `public `[`Edge`](#classEdge)` `[`removeEdge`](#classGraph_1adac871ac0cafe8753d6b3b348b448c8f)`(`[`Vertex`](#classAirport)` source,`[`Vertex`](#classAirport)` destination)` 

Removes the edge between two vertices. 
#### Parameters
* `source` - one vertex the edge is connected to 

* `destination` - the other vertex the edge is connected to 

#### Returns
- if edge exists, remove it and return removed edge

* if not, return InvalidEdge

#### `public `[`Edge`](#classEdge)` `[`setEdgeWeight`](#classGraph_1a115b9d4bcb87fb93949819d4be350acd)`(`[`Vertex`](#classAirport)` source,`[`Vertex`](#classAirport)` destination,double weight)` 

Sets the weight of the edge between two vertices. 
#### Parameters
* `source` - one vertex the edge is connected to 

* `destination` - the other vertex the edge is connected to 

* `weight` - the weight to set to the edge 

#### Returns
- if edge exists, set edge weight and return edge with new weight

* if not, return InvalidEdge

#### `public bool `[`isDirected`](#classGraph_1a08b970ecb424505f85c4f9d632b5ab01)`() const` 

Checks if the graph is directed or not.

Creates a name for snapshots of the graph. 
#### Parameters
* `title` - the name to save the snapshots as Saves a snapshot of the graph to file. initSnapshot() must be run first. Prints the graph to stdout. Saves the graph as a PNG image. 

* `title` - the filename of the PNG image 

#### Returns
true if the graph is directed, false if the graph is not directed

#### `public void `[`clear`](#classGraph_1ac6192a41101102ca8aa6acca607c84f3)`()` 

Clears the graph data.

#### `public void `[`printGraph`](#classGraph_1a5ac05db53839e72af76cdb2bafe88b77)`()` 

Prints the graph to std::cout.

#### `public map< `[`Vertex](#classAirport), map< [Vertex](#classAirport), [Edge`](#classEdge)` > > `[`getList`](#classGraph_1a65b4ec8b396ad94e2269d49482d97516)`()` 

# struct `Airports::dijkstras_graph` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public unordered_map< int, long double > `[`distances`](#structAirports_1_1dijkstras__graph_1a5e890b6209208f88f53c048358c86ec7) | 
`public unordered_map< int, int > `[`parents`](#structAirports_1_1dijkstras__graph_1a128cd8339a3aeb378207250de91c55f0) | 
`public `[`Graph`](#classGraph)` `[`graph`](#structAirports_1_1dijkstras__graph_1a9ba5a3d6e3204d92977f05e86f2f9f3c) | 
`public inline  `[`dijkstras_graph`](#structAirports_1_1dijkstras__graph_1a66c58e1d358a00add893fc81472960b6)`()` | 

## Members

#### `public unordered_map< int, long double > `[`distances`](#structAirports_1_1dijkstras__graph_1a5e890b6209208f88f53c048358c86ec7) 

#### `public unordered_map< int, int > `[`parents`](#structAirports_1_1dijkstras__graph_1a128cd8339a3aeb378207250de91c55f0) 

#### `public `[`Graph`](#classGraph)` `[`graph`](#structAirports_1_1dijkstras__graph_1a9ba5a3d6e3204d92977f05e86f2f9f3c) 

#### `public inline  `[`dijkstras_graph`](#structAirports_1_1dijkstras__graph_1a66c58e1d358a00add893fc81472960b6)`()` 

Generated by [Moxygen](https://sourcey.com/moxygen)