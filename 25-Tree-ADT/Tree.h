#include "Position.h"
//Nonlinear (instead of before and after, think of one above and many below)
//example: family tree, file system
//nodes consist of one parent and 0 or more children
//tree is ordered if there is an order to the children
//parent of null is the root of tree, nodes with the same parent are siblings
//node is external if it has 0 children and internal if it has one or more children
//edge is a parent child relationship, path is a sequence of nodes that form an edge
//no direct node access; access is via a position which is related to a node
//regardless, node/position are interchangeable
class Tree{
public:
    virtual Position root() = 0;           // returns root position of tree
    virtual int size() = 0;                // returns number of nodes in tree
    virtual bool empty() = 0;              // true if tree is empty
    virtual PositionList positions() =  0; // returns all positions in the tree
};
