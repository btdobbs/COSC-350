#include "Node.h"
#include <string>

using namespace std;

class CharacterList{
public:
    ~CharacterList();
    bool empty();
    char front();
    void add_front(char key);
    void add_back(char key);                   //Question 1
    void add_after(char key, char search_key); //Question 2
    void remove_front();
    void remove_back();                        //Question 3
    void remove(char key);                     //Question 4
    bool exists(char key);
    int size();                                //Question 5
    char back();                               //Question 6
    string to_string();
private:
    Node *head = nullptr;
};
