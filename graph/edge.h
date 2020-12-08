/**
 * @file edge.h
 * Definition and (minimal) implementation of an edge class.
 */

#pragma once

#include <string>
#include <limits.h>
#include "../airport/airport.h"
#include "../airline/airline.h"
#include <unordered_set>

using std::string;
typedef Airport Vertex;

/**
 * Represents an edge in a graph; used by the Graph class.
 *
 * @author Sean Massung
 * @date Spring 2012
 */
class Edge
{
  public:
    Vertex source; /**< The source of the edge **/
    Vertex dest; /**< The destination of the edge **/

    /**
     * Parameter constructor for unweighted graphs.
     * @param u - one vertex the edge is connected to
     * @param v - the other vertex it is connected to
     */
    Edge(Vertex u, Vertex v)
        : source(u), dest(v), label(""), weight(-1)
    { /* nothing */
    }

    /**
     * Parameter constructor for unweighted graphs.
     * @param u - one vertex the edge is connected to
     * @param v - the other vertex it is connected to
     * @param lbl - the edge label
     */
    Edge(Vertex u, Vertex v, string lbl)
        : source(u), dest(v), label(lbl), weight(-1)
    { /* nothing */
    }

    /**
     * Parameter constructor for weighted graphs.
     * @param u - one vertex the edge is connected to
     * @param v - the other vertex it is connected to
     * @param w - the weight of the edge
     * @param lbl - the edge label
     */
    Edge(Vertex u, Vertex v, int w, string lbl)
        : source(u), dest(v), label(lbl), weight(w)
    { /* nothing */
    }

    /**
     * Default constructor.
     */
    Edge() : source(), dest(), label(), weight(-1)   
    { /* nothing */
    }

    /**
     * Compares two Edges.
     * operator< is defined so Edges can be sorted with std::sort.
     * @param other - the edge to compare with
     * @return whether the current edge is less than the parameter
     */
    bool operator<(const Edge& other) const
    {
        return weight < other.weight;
    }

    /**
     * Gets edge label.
     */
    string getLabel() const
    {
        return label;
    }

    /**
     * Gets edge weight.
     */
    int getWeight() const
    {
        return this->weight;
    }

    /**
     * Compares two edges' source and dest.
     * @param other - the edge to compare with
     */
    bool operator==(Edge& other) const
    {
        if (source.get_port_ID() != other.source.get_port_ID())
            return false;
        if (dest.get_port_ID() != other.dest.get_port_ID())
            return false;
        return true;
    }
    
    void insertAirline(Airline airline) {
      std::string IATA = airline.get_IATA();
      std::string ICAO = airline.get_ICAO();
      if(IATA != "")
        airlines_.insert(IATA);
      if(ICAO != "")
        airlines_.insert(ICAO);
    }

    void insertAirline(string airline) {
      if(airline != "")
        airlines_.insert(airline);
    }

    bool hasAirline(Airline airline) {
      std::string IATA = airline.get_IATA();
      std::string ICAO = airline.get_ICAO();
      int ans = 0;
      if(IATA != "")
        ans += airlines_.count(IATA);
      if(ICAO != "")
        ans += airlines_.count(ICAO);
      return ans;
    }

    bool hasAirline(string airline) {
      return airlines_.count(airline);
    }

private:
    string label; /**< The edge label **/
    int weight; /**< The edge weight (if in a weighed graph) **/

    //unordered_set to store airlines
    std::unordered_set<string> airlines_;
};