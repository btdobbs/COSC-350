#include "Node.h"
#include <string>

using namespace std;

class CharacterList{
public:
    ~CharacterList();
    bool empty();
    char front();
    void add_front(char key);
    //Question 1
    void add_back(char key);
    //Question 2
    void add_after(char key, char search_key);
    void remove_front();
    //Question 3
    void remove_back();
    //Question 4
    void remove(char key);
    bool exists(char key);
    //Question 5
    int size();
    //Question 6
    char back();
    string to_string();
private:
    Node *head = nullptr;
};