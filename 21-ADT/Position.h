#include "Element.h"

class Position{
public:
    Element element();
    Position next();
    Position previous();
    bool has_next();
    bool has_previous();
};
