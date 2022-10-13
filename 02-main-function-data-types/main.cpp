#include <iostream>

//using a namespace will assume std:: in front of calls that would need the scope declaration
using namespace std;

int main() {
    //a variable lives within the braces its defined
    //(variable is put on the stack when declared and removed at the end brace)
    //value of a variable will cycle back to min if you increment past max value and vice versa
    //only two values allowed for bool but still takes one byte
    bool b = true;
    //sizeof gives bytes used for storage
    //endl is a line return constant in std
    //& in front of variable returns memory address (in hex values 0-F) of variable on the stack
    //Note (void *) is needed with cout so it's not treated like a string
    cout << "boolean: " << b << " size = " << sizeof(b) << " at address " << &b << endl;
    //char is one byte and stored as a number but printed as a character (1 byte = 8 bits so 2^8 values)
    char c = 'z';
    cout << "char: " << c << " size = " << sizeof(c) << " at address " << (void *)&c << endl;
    //short is typically a 2 byte intetger (2 bytes = 16 bits so 2^16 values)
    short s = 1000;
    cout << "short: " << s << " size = " << sizeof(s) << " at address " << &s << endl;
    //int is typically a 4 byte intetger (4 bytes = 32 bits so 2^32 values)
    int i = 51000;
    cout << "int: " << i << " size = " << sizeof(i) << " at address " << &i << endl;
    //long is typically an 8 byte intetger (8 bytes = 64 bits so 2^64 values)
    long l = 1000000000;
    cout << "long: " << l << " size = " << sizeof(l) << " at address " << &l << endl;
    //float is typically a 4 byte real (8 bytes = 64 bits so 2^64 values).  The decimal floats.
    float f = 54.67;
    cout << "float: " << f << " size = " << sizeof(f) << " at address " << &f << endl;
    //double is typically an 8 byte real (8 bytes = 64 bits so 2^64 values)
    double d = 999999.9435;
    cout << "double: " << d << " size = " << sizeof(d) << " at address " << &d << endl;
    //In c++, we can't declare a void variable
    //We will discuss the use of the void type later with functions
    //void v;
    //Note: The memory address change with each variable
    //Note: No strings
    //Note:  The size of any address is typically 8 bytes for 64 bit system (8*8=64)
    cout << "memory address size = " << sizeof(&b) << endl;
    return 0;
}
