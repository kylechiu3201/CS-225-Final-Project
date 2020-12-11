::: {#classGraph}
:::

[\[classGraph\]]{#classGraph label="classGraph"}

\#include $<$graph.h$>$

Collaboration diagram for Graph:

![image](classGraph__coll__graph){width="318pt"}

()

*Constructor to create an empty directed and weighted graph.*

(bool weighted)

(bool weighted, bool directed)

(bool weighted, int numVertices, unsigned long seed)

vector$<$ $>$ ( source) const

() const

vector$<$ $>$ () const

( source, destination) const

vector$<$ $>$ () const

bool ( v) const

bool ( source, destination) const

( source, destination, string label)

string ( source, destination) const

double ( source, destination) const

void ( v)

( v)

bool ( source, destination, airline)

( source, destination)

( source, destination, double weight)

bool () const

*Checks if the graph is directed or not.*

void ()

*Clears the graph data.*

void ()

*Prints the graph to std::cout.*

map$<$ , map$<$ , $>$ $>$ **getList** ()

static

const static

const static double **InvalidWeight**

const static string **InvalidLabel**

Represents a graph; used by the GraphTools class.

Constructor to create an empty graph.

Parameters *weighted* & - specifies whether the graph is a weighted
graph or not\

Constructor to create an empty graph.

Parameters *weighted* & - specifies whether the graph is a weighted
graph or not\
& - specifies whether the graph is directed\

Constructor to create a random, connected graph.

Parameters *weighted* & - specifies whether the graph is a weighted
graph or not\
& - the number of vertices the graph will have\
& - a random seed to create the graph with\

Checks if edge exists between two vertices exists.

Returns - if exists, true

if doesnt exist, return false

Gets all adjacent vertices to the parameter vertex.

Parameters *source* & - vertex to get neighbors from\

Returns a vector of vertices

Gets an edge between two vertices.

Parameters *source* & - one vertex the edge is connected to\
& - the other vertex the edge is connected to\

Returns - if exist, return the corresponding edge

if edge doesnt exist, return

Gets the edge label of the edge between vertices u and v.

Parameters *source* & - one vertex the edge is connected to\
& - the other vertex the edge is connected to\

Returns - if edge exists, return edge label

if edge doesnt exist, return InvalidLabel

Gets all the edges in the graph.

Returns a vector of all the edges in the graph

Gets the weight of the edge between two vertices.

Parameters *source* & - one vertex the edge is connected to\
& - the other vertex the edge is connected to\

Returns - if edge exists, return edge wright

if doesnt, return InvalidWeight

Returns one vertex in the graph. This function can be used to find a
random vertex with which to start a traversal.

Returns a vertex from the graph

Gets all vertices in the graph.

Returns a vector of all vertices in the graph

Inserts an edge between two vertices. A boolean is returned for use with
the random graph generation. Hence, an error is not thrown when it fails
to insert an edge.

Parameters *source* & - one vertex the edge is connected to\
& - the other vertex the edge is connected to\

Returns whether inserting the edge was successful

Inserts a new vertex into the graph and initializes its label as '̈'̈.

Parameters *v* & - the name for the vertex\

Checks if the graph is directed or not.

Creates a name for snapshots of the graph.

Parameters *title* & - the name to save the snapshots as Saves a
snapshot of the graph to file. initSnapshot() must be run first. Prints
the graph to stdout. Saves the graph as a PNG image.\
& - the filename of the PNG image\

Returns true if the graph is directed, false if the graph is not
directed

Removes the edge between two vertices.

Parameters *source* & - one vertex the edge is connected to\
& - the other vertex the edge is connected to\

Returns - if edge exists, remove it and return removed edge

if not, return InvalidEdge

Removes a given vertex from the graph.

Parameters *v* & - the vertex to remove\

Returns - if v exists, return v

if not, return InvalidVertex;

Sets the edge label of the edge between vertices u and v.

Parameters *source* & - one vertex the edge is connected to\
& - the other vertex the edge is connected to\

Returns - if edge exists, set the label to the corresponding edge(if not
directed, set the reverse one too), return edge with new label

if edge doesnt exist, return InvalidEdge

Sets the weight of the edge between two vertices.

Parameters *source* & - one vertex the edge is connected to\
& - the other vertex the edge is connected to\
& - the weight to set to the edge\

Returns - if edge exists, set edge weight and return edge with new
weight

if not, return InvalidEdge

Checks if the given vertex exists.

Returns - if Vertex exists, true

if Vertex doesnt exist, return false

The documentation for this class was generated from the following file:

graph/
