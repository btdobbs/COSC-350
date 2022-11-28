#include "Element.h"

class Vertex{
public:
    virtual Element get_element() = 0;          //Return the element associated with instance.
    virtual EdgeList incident_edges() = 0;      //Return an edge list of the edges incident on instance.
    virtual bool is_adjacent_to(Vertex *v) = 0; //Test whether vertex v is adjacent to instance.
};