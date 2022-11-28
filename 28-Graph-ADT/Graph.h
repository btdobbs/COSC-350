//A graph is a set of vertices or nodes connected via edges.
// examples: mapping, transportation, wiring, plumbing, and computer networks
// An edge is represented by a pair of vertices.
// A graph can be thought of a collection of objects (vertices) with relationships (edges).
// Edges can be directed (tuple), undirected (set), or mixed.
// Edges can have a weight representing a cost to traverse the edge.
// Two vertices are adjacent if they share an edge.
// An edge is incident on a vertex if the vertex is an endpoint.
// The degree of a vertex is calculated by the number of incident edges (self loop count as two).
// The sum of vertex degrees of a graph is always even.
// A duplicate edge is considered a parallel edge.
// An edge connected to itself is a self loop.
// A simple graph has no loops or parallel edges.
// A path is a sequence of connected vertices (path is simple if it has unique vertices).
// A cycle is a path that has at least one edge with same start/end vertex
// (cycle is simple if it has unique vertices except start/end)
// Subgraph has vertices and edges which are a subset of a graph.
// Spanning subgraph will have all the vertices of a graph.
// Connected graph has a path to all vertices.
// A forrest is a graph with no cycles.
// A tree is a connected forest. (free tree vs rooted trees discussed earlier)
// A spanning tree is a spanning subgraph which is a tree.

#include "Vertex.h"
#include "Edge.h"

//simple undirected graph ADT
class Graph{
public:
    virtual VertexList vertices() = 0;                                  //Return a vertex list of all the vertices of the graph.
    virtual EdgeList edges() = 0;                                       //Return an edge list of all the edges of the graph.
    virtual Vertex *insert_vertex(Element x) = 0;                       //Insert and return a new vertex storing element x.
    virtual Edge *insert_edge(Vertex *v1, Vertex *v2, Element x) = 0;      //Insert and return a new undirected edge with end vertices v1 and v2 and storing element x.
    virtual void erase_vertex(Vertex v) = 0;                            //Remove vertex v and all its incident edges.
    virtual void erase_edge(Edge e) = 0;                                //Remove edge e.
};

// Implementation via edge list, adjacency list, and adjacency matrix (2D array)