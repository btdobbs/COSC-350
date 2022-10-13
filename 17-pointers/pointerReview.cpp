#include <iostream>

int main() {
    int *ptr;
    int x;

    //Note size of pointer is size of address space (8 bytes now and 8 bits x 8 bytes = 64 bit)
    std::cout << sizeof(ptr) << std::endl;
    std::cout << sizeof(x) << std::endl;
    //same as pointer size
    std::cout << sizeof(&x) << std::endl;
    //print actual address stored in pointer (this is just some value in memory because we haven't initialized with heap address yet)
    std::cout << ptr << std::endl;
    //have os provide real memory address from heap
    ptr = new int;
    //note memory addressed changed from before
    std::cout << ptr << std::endl;
    //set a value to the int in the heap
    *ptr = 5;
    std::cout << *ptr << std::endl;
    x = 7;
    //set the address of the pointer to the address of x.  this sets the value of *ptr to 7
    ptr = &x;
    //Note the values are the same mow
    std::cout << *ptr << std::endl;
    std::cout << x << std::endl;
    //delete will not work because we set to a stack memory address.  Also original memory address allocated by new is not cleaned up
    delete ptr;
    return 0;
}
