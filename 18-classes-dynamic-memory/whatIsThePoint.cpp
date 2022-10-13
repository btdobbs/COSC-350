#include <iostream>

using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point();
    Point(int x, int y);
    int getX() const;
    int getY() const;
    void print() const;
    bool operator==(const Point& point) const;
    bool operator!=(const Point& point) const;
};

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y){
    this->x = x;
    this->y = y;
}

int Point::getX() const {return this->x;}

int Point::getY() const {return this->y;}

void Point::print() const
{
    cout << "(" << this->getX() << "," << this->getY() << ")" << endl;
}

bool Point::operator==(const Point &point) const
{
    return (this->getX() == point.getX()) && (this->getY()== point.getY());
}

bool Point::operator!=(const Point &point) const
{
    return (this->getX() != point.getX()) || (this->getY() != point.getY());
}

class Points{
private:
    Point *points;
    int size;
public:
    Points();
    ~Points();
    void print();
    int getCount() const;
    void add(Point point);
    void remove(Point point);
    void remove(int index);
    Point& operator[](int index);
};

Points::Points()
{
    this->size = 0;
    points = nullptr;
}

Points::~Points()
{
    delete[] points;
}

void Points::print()
{
    cout << this->getCount() << " total point(s)" << endl;
    for(int i = 0; i < this->size; i++) {
        points[i].print();
    }
}

int Points::getCount() const
{
    return this->size;
}

void Points::add(Point point)
{
    Point *temp;
    temp = new Point[this->size + 1];
    for(int i = 0; i < this->size; i++)
    {
        temp[i] = points[i];
    }
    if (this->size > 0)
        delete[] points;
    points = temp;
    points[this->size] = point;
    this->size = this->size + 1;
}

void Points::remove(Point point)
{
    int removeCount = 0;
    for(int i = 0; i < this->size; i++)
    {
        if (points[i] == point)
            removeCount++;
    }
    if (removeCount == 0)
    {
        cout << "Index does not exist." << endl;
        return;
    }
    Point *temp;
    temp = new Point[this->size - removeCount];
    int tempIndex = 0;
    for(int i = 0; i < this->size; i++)
    {
        if (points[i] != point){
            temp[tempIndex] = points[i];
            tempIndex++;
        }
    }
    points = temp;
    this->size = this->size - removeCount;
}

void Points::remove(int index) {
    if ((index > this->size - 1) || (index < 0)) {
        cout << "Index does not exist." << endl;
        return;
    }
    if (this->size == 1) {
        delete[] points;
        points = nullptr;
    } else
    {
        Point *temp;
        temp = new Point[this->size - 1];
        for(int i = 0; i < this->size; i++)
        {
            if (i < index)
                temp[i] = points[i];
            else
                temp[i] = points[i+1];
        }
        delete[] points;
        points = temp;
    }
    this->size = this->size - 1;
}

Point& Points::operator[](int index)
{
    return points[index];
}

void promptAddPoint(Points& points)
{
    int x;
    int y;
    cout << "Enter a value for x:" << endl;
    cin >> x;
    cout << "Enter a value for y:" << endl;
    cin >> y;
    points.add(Point(x,y));
}

void promptRemovePoint(Points& points)
{
    int x;
    int y;
    cout << "Enter a value for x:" << endl;
    cin >> x;
    cout << "Enter a value for y:" << endl;
    cin >> y;
    points.remove(Point(x,y));
}

void promptRemovePointByIndex(Points& points)
{
    int index;
    cout << "Enter index:" << endl;
    cin >> index;
    points.remove(index);
}

int main() {
    Points points;
    char input = '\0';
    do {
        cout << "Choose a command:  (a)dd point, (r)emove point, remove point by (i)ndex, (p)rint point(s), (e)xit" << endl;
        cin >> input;
        switch (input) {
            case 'a':
                promptAddPoint(points);
                break;
            case 'r':
                promptRemovePoint(points);
                break;
            case 'i':
                promptRemovePointByIndex(points);
                break;
            case 'p':
                points.print();
                break;
            default:
                break;
        }
    } while (input != 'e');
    return 0;
}
