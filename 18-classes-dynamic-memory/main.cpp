#include <iostream>
using namespace std;

class DynamicIntegerArray {
private:
    int *array;
    int size;
public:
    DynamicIntegerArray();
    explicit DynamicIntegerArray(int size);
    ~DynamicIntegerArray();
    void print();
    void expand(int amount);
    int getSize() const;
    int& operator[](int index);
};

DynamicIntegerArray::DynamicIntegerArray()
{
    this->size = 1;
    array = new int[this->size];
    array[0] = 0;
}

DynamicIntegerArray::DynamicIntegerArray(int size)
{
    this->size = size;
    array = new int[this->size];
    for(int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}

DynamicIntegerArray::~DynamicIntegerArray()
{
    delete[] array;
}

void DynamicIntegerArray::print()
{
    for(int i = 0; i < this->size; i++)
    {
        cout << array[i];
        if (i < this->size-1)
            cout << ", ";
    }
    cout << " (size = " << this->size << ")";
}

void DynamicIntegerArray::expand(int amount)
{
    int *temp = new int[this->size + amount];
    for(int i = 0; i < this->size; i++)
    {
        temp[i] = array[i];
    }
    //Below is a quick way to perform the above for loop in one line
    //copy(array,array+this->size,temp);
    delete[] array;
    array = temp;
    this->size = this->size + amount;
    for(int i = amount; i < this->size; i++)
    {
        array[i] = 0;
    }
}

int DynamicIntegerArray::getSize() const
{
    return this->size;
}

int& DynamicIntegerArray::operator[](int index)
{
    return array[index];
}


int main() {
    DynamicIntegerArray a1;
    cout << "\na1\n";
    a1.print();
    DynamicIntegerArray a2(10);
    cout << "\na2\n";
    a2.print();
    a1[0] = 5;
    a1.expand(5);
    cout << "\na1\n";
    a1[4]=100;
    a1.print();
    cout << endl;
    for (int i = 0; i < a1.getSize(); i++)
    {
        cout << "a1[" << i << "] = " << a1[i] << endl;
    }
    return 0;
}
