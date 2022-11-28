#include "Element.h"

class Edge{
public:
    virtual Element get_element() = 0;          //Return the element associated with instance.
    virtual VertexList end_vertices() = 0;      //Return a vertex list containing instance's end vertices.
    virtual Vertex opposite(Vertex v) = 0;      //Return the end vertex of edge e distinct from vertex v; an error occurs if e is not incident on v.
    virtual bool is_adjacent_to(Edge *e) = 0;   //Test whether edge e and instance are adjacent.
    virtual bool is_incident_on(Vertex v) = 0;  //Test whether instance is incident on v.
};