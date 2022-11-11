#include "Queue.h"
#include <string>

using namespace std;

class ArrayQueue : Queue{
private:
    int _front = 0;
    int _back = 0;
    int _size = 0;
    int _max_size = 4;
    Element *a;
    void grow();
    void shift();
    void reset_front();
public:
    ArrayQueue();
    ~ArrayQueue();
    void enqueue(Element e) override;
    void dequeue() override;
    Element front() override;
    int size() override;
    bool empty() override;
    string to_string() const;
};
