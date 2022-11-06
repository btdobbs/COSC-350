#import "Position.h"

class Sequence{
public:
    Position begin();
    Position end();
    void insert_front(Element e);
    void insert_back(Element e);
    void insert(Position p, Element e);
    void remove_front();
    void remove_back();
    void remove(Position p);
    Position at_index(int i);
    int index_of(Position p);
};