#include "Queue.h"
#include "Node.h"
#include <string>

using namespace std;

class ListQueue : Queue{
private:
    int _size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
public:
    ~ListQueue();
    void enqueue(Element e) override;
    void dequeue() override;
    Element front() override;
    int size() override;
    bool empty() override;
    string to_string() const;
};
