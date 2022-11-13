#include "Tree.h"
#include <iostream>

using namespace std;

//count of the ancestors of position (excluding itself)
//worse case running time n calls where n is the total number of nodes
//often used d calls where d is the depth because it is more likely
int depth(Position *position){
    if (position->is_root())
        return 0;
    else
        return 1 + depth(position->parent());
}

//maximum depth of the external nodes of position
//running time, n calls where n is the total number of nodes
int height(Position *position){
    if (position->is_external())
        return 0;
    int h = 0;
    PositionList *position_list = position->children();
    for(int i = 0; i < position_list->count(); i ++){
        Position *p = position_list->at(i);
        h = std::max(h, height(p));
    }
    return 1 + h;
}

//visit nodes starting with parent and ending with children
void preorder_traverse(Position *position){
    cout << position->get_element().to_string();
    PositionList *position_list = position->children();
    for(int i = 0; i < position_list->count(); i ++){
        Position *p = position_list->at(i);
        preorder_traverse(p);
    }
}

//visit nodes starting with children and ending with parent
void postorder_traverse(Position *position){
    PositionList *position_list = position->children();
    for(int i = 0; i < position_list->count(); i ++){
        Position *p = position_list->at(i);
        postorder_traverse(p);
    }
    cout << position->get_element().to_string();
}

//non-working app built on interfaces (no implementation)
int main(){
    Position *p;
    int d = depth(p);
    int h = height(p);
    preorder_traverse(p);
    postorder_traverse(p);
}
