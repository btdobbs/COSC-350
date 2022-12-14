#include <iostream>
#include <list>

using namespace std;
using std::list;

class Point{
public:
    inline Point(int x, int y) {this->x = x; this->y = y;}
    inline bool operator < (const Point &point) const { return (this->x + this->y) < (point.x + point.y);}
    int x = 0;
    int y = 0;
};

std::ostream &operator<<(std::ostream &os, Point const &point) {
    return os << "(" << point.x << "," << point.y << ")";
}

template <typename T>
T generic_min(T a, T b) {
    return (a < b ? a : b);
}

//How to use the Element class IRL
int main() {
    //function template
    cout << generic_min<int>(3,4) << endl;
    cout << generic_min<float>(30.45,4.45) << endl;
    Point p1(3,5);
    Point p2(5,5);
    cout << generic_min<Point>(p1,p2) << endl;
    //ADT template
    list<int> int_list;
    list<string> string_list;
    list<Point> point_list;
    int_list.push_back(3);
    string_list.emplace_back("hello");
    point_list.emplace_back(p1);
    return 0;
}

