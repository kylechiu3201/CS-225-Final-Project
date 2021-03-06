#include <map>
#include <string>

#include "graph.h"
#include "edge.h"

using std::stoi;
using std::string;

Vertex Graph::InvalidVertex = Airport();  // make invalid airport?
const double Graph::InvalidWeight = INT_MIN;
const string Graph::InvalidLabel = "INVALID LABEL";
const Edge Graph::InvalidEdge = Edge(Graph::InvalidVertex, Graph::InvalidVertex,
                                     Graph::InvalidWeight, Graph::InvalidLabel);

Graph::Graph() {
  this->weighted = true;
  this->directed = true;
}

Graph::Graph(bool weighted) { this->weighted = weighted; }

Graph::Graph(bool weighted, bool directed)
    : weighted(weighted), directed(directed) {}

vector<Vertex> Graph::getAdjacent(Vertex source) const {
  auto lookup = adjacency_list.find(source);

  if (lookup == adjacency_list.end())
    return vector<Vertex>();

  else {
    vector<Vertex> vertex_list;
    map<Vertex, Edge>& map1 = adjacency_list[source];
    for (auto it = map1.begin(); it != map1.end(); it++) {
      vertex_list.push_back(it->first);
    }
    return vertex_list;
  }
}

Vertex Graph::getStartingVertex() const {
  return adjacency_list.begin()->first;
}

vector<Vertex> Graph::getVertices() const {
  vector<Vertex> ret;
  if (adjacency_list.empty()) {
    return ret;
  }
  for (auto it = adjacency_list.begin(); it != adjacency_list.end(); it++) {
    ret.push_back(it->first);
  }

  return ret;
}

Edge Graph::getEdge(Vertex source, Vertex destination) const {
  if (assertEdgeExists(source, destination, __func__) == false) return Edge();
  Edge ret = adjacency_list[source][destination];
  return ret;
}

vector<Edge> Graph::getEdges() const {
  if (adjacency_list.empty()) return vector<Edge>();

  vector<Edge> ret;
  set<pair<Vertex, Vertex>> seen;

  for (auto it = adjacency_list.begin(); it != adjacency_list.end(); it++) {
    Vertex source = it->first;
    for (auto its = adjacency_list[source].begin();
         its != adjacency_list[source].end(); its++) {
      Vertex destination = its->first;
      if (seen.find(make_pair(source, destination)) == seen.end()) {
        // this pair is never added to seen
        ret.push_back(its->second);
        seen.insert(make_pair(source, destination));
        if (!directed) {
          seen.insert(make_pair(destination, source));
        }
      }
    }
  }

  return ret;
}

bool Graph::vertexExists(Vertex v) const { return assertVertexExists(v, ""); }

bool Graph::edgeExists(Vertex source, Vertex destination) const {
  return assertEdgeExists(source, destination, "");
}

Edge Graph::setEdgeLabel(Vertex source, Vertex destination, string label) {
  if (assertEdgeExists(source, destination, __func__) == false)
    return InvalidEdge;
  Edge e = adjacency_list[source][destination];
  Edge new_edge(source, destination, e.getWeight(), label);
  adjacency_list[source][destination] = new_edge;

  if (!directed) {
    Edge new_edge_reverse(destination, source, e.getWeight(), label);
    adjacency_list[destination][source] = new_edge_reverse;
  }
  return new_edge;
}

string Graph::getEdgeLabel(Vertex source, Vertex destination) const {
  if (assertEdgeExists(source, destination, __func__) == false)
    return InvalidLabel;
  return adjacency_list[source][destination].getLabel();
}

double Graph::getEdgeWeight(Vertex source, Vertex destination) const {
  if (!weighted) error("can't get edge weights on non-weighted graphs!");

  if (assertEdgeExists(source, destination, __func__) == false)
    return InvalidWeight;
  return adjacency_list[source][destination].getWeight();
}

void Graph::insertVertex(Vertex v) {
  // will overwrite if old stuff was there
  removeVertex(v);
  // make it empty again
  adjacency_list[v] = map<Vertex, Edge>();
}

Vertex Graph::removeVertex(Vertex v) {
  if (adjacency_list.find(v) != adjacency_list.end()) {
    if (!directed) {
      for (auto it = adjacency_list[v].begin(); it != adjacency_list[v].end();
           it++) {
        Vertex u = it->first;
        adjacency_list[u].erase(v);
      }
      adjacency_list.erase(v);
      return v;
    }

    adjacency_list.erase(v);
    for (auto it2 = adjacency_list.begin(); it2 != adjacency_list.end();
         it2++) {
      Vertex u = it2->first;
      if (it2->second.find(v) != it2->second.end()) {
        it2->second.erase(v);
      }
    }
    return v;
  }

  return InvalidVertex;
}

/* bool Graph::insertEdge(Vertex source, Vertex destination) */
/* { */
/*     if(adjacency_list.find(source)!= adjacency_list.end() */
/*     && adjacency_list[source].find(destination)!=
 * adjacency_list[source].end()) */
/*     { */
/*         //edge already exit */
/*         return false; */
/*     } */

/*     if(adjacency_list.find(source)==adjacency_list.end()) */
/*     { */
/*         adjacency_list[source] = map<Vertex, Edge>(); */
/*     } */
/*         //source vertex exists */
/*     adjacency_list[source][destination] = Edge(source, destination); */
/*     if(!directed) */
/*     { */
/*         if(adjacency_list.find(destination)== adjacency_list.end()) */
/*         { */
/*             adjacency_list[destination] = map<Vertex, Edge>(); */
/*         } */
/*         adjacency_list[destination][source] = Edge(source, destination); */
/*     } */

/*     return true; */
/* } */

bool Graph::insertEdge(Vertex source, Vertex destination, Airline airline) {
  if (adjacency_list.find(source) != adjacency_list.end() &&
      adjacency_list[source].find(destination) !=
          adjacency_list[source].end()) {
    // edge already exit
    std::string IATA = airline.get_IATA();
    std::string ICAO = airline.get_ICAO();
    return false;
  }

  if (adjacency_list.find(source) == adjacency_list.end()) {
    adjacency_list[source] = map<Vertex, Edge>();
  }
  // source vertex exists
  adjacency_list[source][destination] = Edge(source, destination);
  std::string IATA = airline.get_IATA();
  std::string ICAO = airline.get_ICAO();

  // our graph always directed
  // if(!directed)
  // {
  //     if(adjacency_list.find(destination)== adjacency_list.end())
  //     {
  //         adjacency_list[destination] = map<Vertex, Edge>();
  //     }
  //     adjacency_list[destination][source] = Edge(source, destination);
  //     if(IATA != "")
  //       adjacency_list[destination][source].insertAirline(IATA);
  //     if(ICAO != "")
  //       adjacency_list[destination][source].insertAirline(ICAO);
  // }

  return true;
}

Edge Graph::removeEdge(Vertex source, Vertex destination) {
  if (assertEdgeExists(source, destination, __func__) == false)
    return InvalidEdge;
  Edge e = adjacency_list[source][destination];
  adjacency_list[source].erase(destination);
  // if undirected, remove the corresponding edge
  if (!directed) {
    adjacency_list[destination].erase(source);
  }
  return e;
}

Edge Graph::setEdgeWeight(Vertex source, Vertex destination, double weight) {
  if (assertEdgeExists(source, destination, __func__) == false)
    return InvalidEdge;
  Edge e = adjacency_list[source][destination];
  // std::cout << "setting weight: " << weight << std::endl;
  Edge new_edge(source, destination, weight, e.getLabel());
  adjacency_list[source][destination] = new_edge;

  if (!directed) {
    Edge new_edge_reverse(destination, source, weight, e.getLabel());
    adjacency_list[destination][source] = new_edge_reverse;
  }

  return new_edge;
}

bool Graph::assertVertexExists(Vertex v, string functionName) const {
  if (adjacency_list.find(v) == adjacency_list.end()) {
    if (functionName != "")
      error(functionName + " called on nonexistent vertices");
    return false;
  }
  return true;
}

bool Graph::assertEdgeExists(Vertex source, Vertex destination,
                             string functionName) const {
  if (assertVertexExists(source, functionName) == false) return false;
  if (adjacency_list[source].find(destination) ==
      adjacency_list[source].end()) {
    if (functionName != "")
      error(functionName + " called on nonexistent edge " + source.get_name() +
            " -> " + destination.get_name());
    return false;
  }

  if (!directed) {
    if (assertVertexExists(destination, functionName) == false) return false;
    if (adjacency_list[destination].find(source) ==
        adjacency_list[destination].end()) {
      if (functionName != "")
        error(functionName + " called on nonexistent edge " +
              destination.get_name() + " -> " + source.get_name());
      return false;
    }
  }
  return true;
}

bool Graph::isDirected() const { return directed; }

void Graph::clear() { adjacency_list.clear(); }

map<Vertex, map<Vertex, Edge>> Graph::getList() { return adjacency_list; }

void Graph::printGraph() {
  std::cout << "Vertices: " << std::endl;
  auto vertices = getVertices();
  auto edges = getEdges();
  for (auto v : vertices) /* std::cout << v.get_port_ID() << std::endl; */
    std::cout << v.get_ICAO() << std::endl;
  std::cout << std::endl << std::endl << std::endl;
  for (auto e : edges) {
    std::cout << e.source.get_port_ID() << " to " << e.dest.get_port_ID()
              << " ";
  }
}

/**
 * Prints a graph error and quits the program.
 * The program is exited with a segfault to provide a stack trace.
 * @param message - the error message that is printed
 */
void Graph::error(string message) const {
  cerr << "\033[1;31m[Graph Error]\033[0m " + message << endl;
}

/**
 * Creates a name for snapshots of the graph.
 * @param title - the name to save the snapshots as
 */
// void Graph::initSnapshot(string title)
// {
//     picNum = 0;
//     picName = title;
// }

/**
 * Saves a snapshot of the graph to file.
 * initSnapshot() must be run first.
 */
// void Graph::snapshot()
// {
//     std::stringstream ss;
//     ss << picNum;
//     string newName = picName + ss.str();
//     savePNG(newName);
//     ++picNum;
// }

/**
 * Prints the graph to stdout.
 */
// void Graph::print() const
// {
//     for (auto it = adjacency_list.begin(); it != adjacency_list.end(); ++it)
//     {
//         cout << it->first.get_name() << endl;
//         for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
//         {
//             std::stringstream ss;
//             ss << it2->first.get_name();
//             string vertexColumn = "    => " + ss.str();
//             vertexColumn += " " ;
//             cout << std::left << std::setw(26) << vertexColumn;
//             string edgeColumn = "edge label = \"" + it2->second.getLabel()+
//             "\""; cout << std::left << std::setw(26) << edgeColumn; if
//             (weighted)
//                 cout << "weight = " << it2->second.getWeight();
//             cout << endl;
//         }
//         cout << endl;
//     }
// }

/**
 * Saves the graph as a PNG image.
 * @param title - the filename of the PNG image
 */
// void Graph::savePNG(string title) const
// {
//     std::ofstream neatoFile;
//     string filename = "images/" + title + ".dot";
//     neatoFile.open(filename.c_str());

//     if (!neatoFile.good())
//         error("couldn't create " + filename + ".dot");

//     neatoFile
//         << "strict graph G {\n"
//         << "\toverlap=\"false\";\n"
//         << "\tdpi=\"1300\";\n"
//         << "\tsep=\"1.5\";\n"
//         << "\tnode [fixedsize=\"true\", shape=\"circle\",
//         fontsize=\"7.0\"];\n"
//         << "\tedge [penwidth=\"1.5\", fontsize=\"7.0\"];\n";

//     vector<Vertex> allv = getVertices();
//     //lambda expression
//     sort(allv.begin(), allv.end(), [](const Vertex& lhs, const Vertex& rhs) {
//         return lhs.get_port_ID() > rhs.get_port_ID();
//     });

//     int xpos1 = 100;
//     int xpos2 = 100;
//     int xpos, ypos;
//     for (auto it : allv) {
//         string current = it.get_name();
//         neatoFile
//             << "\t\""
//             << current
//             << "\"";
//         if (current[1] == '1') {
//             ypos = 100;
//             xpos = xpos1;
//             xpos1 += 100;
//         }
//         else {
//             ypos = 200;
//             xpos = xpos2;
//             xpos2 += 100;
//         }
//         neatoFile << "[pos=\""<< xpos << "," << ypos <<"\"]";
//         neatoFile << ";\n";
//     }

//     neatoFile << "\tedge [penwidth=\"1.5\", fontsize=\"7.0\"];\n";

//     for (auto it = adjacency_list.begin(); it != adjacency_list.end(); ++it)
//     {
//         for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
//         {
//             string vertex1Text = it->first.get_name();
//             string vertex2Text = it2->first.get_name();

//             neatoFile << "\t\"" ;
//             neatoFile << vertex1Text;
//             neatoFile << "\" -- \"" ;
//             neatoFile << vertex2Text;
//             neatoFile << "\"";

//             string edgeLabel = it2->second.getLabel();
//             if (edgeLabel == "WIN") {
//                 neatoFile << "[color=\"blue\"]";
//             } else if (edgeLabel == "LOSE") {
//                 neatoFile << "[color=\"red\"]";
//             } else {
//                 neatoFile << "[color=\"grey\"]";
//             }
//             if (weighted && it2->second.getWeight() != -1)
//                 neatoFile << "[label=\"" << it2->second.getWeight() << "\"]";

//             neatoFile<< "[constraint = \"false\"]" << ";\n";
//         }
//     }

//     neatoFile << "}";
//     neatoFile.close();
//     string command = "neato -n -Tpng " + filename + " -o " + "images/" +
//     title
//                      + ".png 2> /dev/null";
//     int result = system(command.c_str());

//     if (result == 0) {
//         cout << "Output graph saved as images/" << title << ".png" << endl;
//     } else {
//         cout << "Failed to generate visual output graph using `neato`.
//         Install `graphviz` or `neato` to generate a visual graph." << endl;
//     }

//     string rmCommand = "rm -f " + filename + " 2> /dev/null";
//     system(rmCommand.c_str());
// }
