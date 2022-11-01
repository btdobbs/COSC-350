#include <iostream>
#include <cmath>
using namespace std;

const int matrix_size = 4;

void print(const int a[], int size){
    cout << "[";
    for(int i = 0; i < size-1; i++){
        cout << a[i] << ",";
    }
    if (size > 0)
        cout << a[size-1];
    cout << "]" << endl;
}

//Write a recursive C++ function that finds the maximum integer in an array of integers.
//a is then input array, size is the size of the input array
int max(const int a[], const int size){

}

//Write a recursive C++ function that finds the sum of all the elements in a square matrix (2D n x n array) of integers.
//matrix_size is set to 4 for your test, but your code should handle any value for matrix_size
int matrix_sum(const int a[matrix_size][matrix_size], const int row){

}

//Write a recursive C++ function that computes the product of two positive integers using only addition and subtraction.
// n and m such that the product is n*m
int product(const int n, const int m)
{

}

//Write a recursive C++ function that determines if a string s has more vowels than consonants.
//s is the string to check, index is the index of the string being processed
//a positive return value indicates the string has more vowels
int has_more_vowels(const string &s, const u_long index = -1){

}

//Write a recursive C++ function that determines if a string s is a palindrome, that is, it is equal to its reverse.
//s is the string to test, i and j are the indexes of the characters being tested
bool is_palindrome(const string &s, const u_long i = -1, const u_long j = -1){

}

//Write a recursive C++ function that will rearrange an array of int values so that all the even values appear before all the odd values.
//a is then input array, size is the size of the input array
//for this exercise, it's ok to mutate a (don't worry about the function design pattern)
void even_before_odd(int a[], const int size){

}

//Write a recursive C++ function that finds the minimum and maximum values in an array of int values without using any loops.
//a is the input array, minmax is an array of minmax values, size is the size of the input array
//for this exercise, it's ok to mutate minmax (don't worry about the function design pattern)
void min_max(const int a[], int minmax[2], const int size){

}

//Write a recursive C++ function that converts a string of digits into the integer it represents.
//s is the string to convert, index is the index of the string being processed
int string_to_int(string &s, const u_long index = -1){

}

int main() {
    const int size = 8;
    int a[size] = {85,24,63,45,17,31,96,50};

    cout << "q1" << endl;
    int m = max(a, size);
    cout << m << endl; //prints 96

    cout << endl << "q2" << endl;
    int x[matrix_size][matrix_size] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}, {12,13,14,15}};
    int s = matrix_sum(x,matrix_size);
    cout << s << endl; //prints 120

    cout << endl << "q3" << endl;
    int p = product(5,3);
    cout << p << endl; //prints 15

    cout << endl << "q4" << endl;
    string str = "This string does not have more vowels.";
    int b1 = has_more_vowels(str);
    cout << b1 << endl;  //prints -9
    str = "aeiou";
    b1 = has_more_vowels(str);
    cout << b1 << endl; //prints 5
    str = "aabb";
    b1 = has_more_vowels(str);
    cout << b1 << endl; //prints 0

    cout << endl << "q5" << endl;
    bool b2 = is_palindrome("racecar");
    cout << b2 << endl; //prints 1
    b2 = is_palindrome("gohangasalamiimalasagnahog");
    cout << b2 << endl; //prints 1
    b2 = is_palindrome("not a palindrome");
    cout << b2 << endl; //prints 0

    cout << endl << "q6" << endl;
    even_before_odd(a,size);
    print(a, size); //prints [50,24,96,85,63,45,17,31]

    cout << endl << "q7" << endl;
    int mm[2] = {0,0};
    min_max(a,mm,size);
    print(mm, 2); //prints [17,96]

    cout << endl << "q8" << endl;
    string i = "13531";
    int j = string_to_int(i);
    cout << j << endl; //prints 13531

    return 0;
}
