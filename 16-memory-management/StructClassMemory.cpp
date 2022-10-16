#include <iostream>

using namespace std;

class CEmpty{

};

struct SEmpty{

};

struct SPoint{
    int x = 0;
    int y = 0;
    bool visible = false;
};

class CPoint{
private:
    int x;
    int y;
    bool visible;
public:
    CPoint();
    int getX() const;
    int getY() const;
    bool isVisible() const;
};

CPoint::CPoint() {
    this->x = 0;
    this->y = 0;
    this->visible = false;
}

int CPoint::getX() const {
    return this->x;
}

int CPoint::getY() const {
    return this->y;
}

bool CPoint::isVisible() const {
    return this->visible;
}

int main() {
    CEmpty e1;
    SEmpty e2;
    CPoint p1;
    SPoint p2;
    CPoint *p3;
    SPoint *p4;
    cout << "Size of int in bytes is: " << sizeof(int) << endl;
    cout << "Size of bool in bytes is: " << sizeof(bool) << endl;
    //Even empty class and structure take one byte of space
    cout << "Size of empty class in bytes is: " << sizeof(e1) << endl;
    cout << "Size of empty structure in bytes is: " << sizeof(e2) << endl;
    //Even though size should be 9, some compilers will show 12 here due to
    // 2n byte block memory allocation.  Whether you get 5 or 12 depends on pack default
    // which can be changed with a pragma and this is out of scope for this class.
    cout << "Size of class in bytes is: " << sizeof(p1) << endl;
    cout << "Size of structure in bytes is: " << sizeof(p2) << endl;
    cout << "Size of pointer to class in bytes is: " << sizeof(p3) << endl;
    cout << "Size of pointer to structure in bytes is: " << sizeof(p4) << endl;
    return 0;
}
