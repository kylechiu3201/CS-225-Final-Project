::: {#classEdge}
:::

[\[classEdge\]]{#classEdge label="classEdge"}

\#include $<$edge.h$>$

Collaboration diagram for Edge:

![image](classEdge__coll__graph){width="138pt"}

( u, v)

( u, v, string lbl)

( u, v, double w, string lbl)

()

bool (const &other) const

string () const

double () const

bool ( &other) const

Represents an edge in a graph; used by the class.

Author Sean Massung

Date Spring 2012

Parameter constructor for unweighted graphs.

Parameters *u* & - one vertex the edge is connected to\
& - the other vertex it is connected to\

Parameter constructor for unweighted graphs.

Parameters *u* & - one vertex the edge is connected to\
& - the other vertex it is connected to\
& - the edge label\

Parameter constructor for weighted graphs.

Parameters *u* & - one vertex the edge is connected to\
& - the other vertex it is connected to\
& - the weight of the edge\
& - the edge label\

Default constructor.

Gets edge label.

Gets edge weight.

Compares two Edges. operator$<$ is defined so Edges can be sorted with
std::sort.

Parameters *other* & - the edge to compare with\

Returns whether the current edge is less than the parameter

Compares two edges source and dest.

Parameters *other* & - the edge to compare with\

The destination of the edge

The source of the edge

The documentation for this class was generated from the following file:

graph/
