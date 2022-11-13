#include "Element.h"

class Position;

class PositionList{
public:
    virtual int count() = 0;
    virtual Position *at(int index) = 0;
};

//note pointer return types due to virtual class
class Position{
public:
    virtual Element get_element() = 0;    //element related to the position
    virtual Position *parent() = 0;       //parent position of the position
    virtual PositionList *children() = 0;  //list of child positions for the position
    virtual bool is_root() = 0;           //true if this is a root node
    virtual bool is_external() = 0;       //ture if this node has children
};