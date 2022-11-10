#include "Stack.h"

class HundredArrayStack : Stack{
private:
    int _size = 0;
    Element a[100]={};
public:
    void push(Element e) override;
    void pop() override;
    Element top() override;
    int size() override;
    bool empty() override;
};
