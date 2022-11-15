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
    int index = size - 1;
    if (index == 0)
        return a[0];
    int m = max(a,index);
    if (a[index] > m)
        return a[index];
    return m;
}

int max2(const int a[], const int size){
    if (size == 1)
        return a[0];
    else if (size == 2) {
        if (a[0] > a[1])
            return a[0];
        else
            return a[1];
    }
    else {
        int midpoint = size/2;
        int a1[midpoint];
        int a2[midpoint];
        for (int i = 0; i < midpoint; i++)
            a1[i] = a[i];
        for (int i = midpoint; i < size; i++)
            a2[i-midpoint] = a[i];
        int m1 = max2(a1, midpoint);
        int m2 = max2(a2, midpoint);
        if (m1 > m2)
            return m1;
        return m2;
    }
}

//Write a recursive C++ function that finds the sum of all the elements in a square matrix (2D n x n array) of integers.
//matrix_size is set to 4 for your test, but your code should handle any value for matrix_size
int matrix_sum(const int a[matrix_size][matrix_size], const int row){
    int row_index = row -1;
    if (row_index == -1)
        return 0;
    int sum = 0;
    for (int i = 0; i < matrix_size; i++)
        sum+=a[row_index][i];
    return sum + matrix_sum(a,row_index);
}

//Write a recursive C++ function that computes the product of two positive integers using only addition and subtraction.
// n and m such that the product is n*m
int product(const int n, const int m)
{
    if (m == 1)
        return n;
    return n + product(n,m-1);
}

//Write a recursive C++ function that determines if a string s has more vowels than consonants.
//s is the string to check, index is the index of the string being processed
//a positive return value indicates the string has more vowels
int has_more_vowels(const string &s, const u_long index = -1){
    u_long string_index = index-1;
    if (index == -1)
        return has_more_vowels(s, s.length());
    if (string_index == -1)
        return 0;
    if ((s[string_index] > 64 && s[string_index] < 91) || (s[string_index] > 96 && s[string_index] < 123)) {
        if (s[string_index] == 'a' || s[string_index] == 'e' || s[string_index] == 'i' || s[string_index] == 'o' ||
            s[string_index] == 'u' ||
            s[string_index] == 'A' || s[string_index] == 'E' || s[string_index] == 'I' || s[string_index] == 'O' ||
            s[string_index] == 'U')
            return has_more_vowels(s, string_index) + 1;
        else
            return has_more_vowels(s, string_index) - 1;
    }
    return has_more_vowels(s, string_index);
}

//Write a recursive C++ function that determines if a string s is a palindrome, that is, it is equal to its reverse.
//s is the string to test, i and j are the indexes of the characters being tested
bool is_palindrome(const string &s, const u_long i = -1, const u_long j = -1){
    if (i == -1 && j == -1)
        return is_palindrome(s, 0, s.length()-1);
    if (j < i || j == i)
        return true;
    return (s[i] == s[j]) && is_palindrome(s, i+1, j-1);
}

//Write a recursive C++ function that will rearrange an array of int values so that all the even values appear before all the odd values.
//a is then input array, size is the size of the input array
//for this exercise, it's ok to mutate a (don't worry about the function design pattern)
void even_before_odd(int a[], const int size){
    int index = size - 1;
    if (index == 0)
        return;
    if (a[index] % 2 == 0) {
        for (int i = 0; i < size; i++) {
            if (a[i] % 2 != 0) {
                int temp = a[i];
                a[i] = a[index];
                a[index] = temp;
                even_before_odd(a,index);
            }
        }
        return;
    }
    even_before_odd(a,index);
}

//Write a recursive C++ function that finds the minimum and maximum values in an array of int values without using any loops.
//a is the input array, minmax is an array of minmax values, size is the size of the input array
//for this exercise, it's ok to mutate minmax (don't worry about the function design pattern)
void min_max(const int a[], int minmax[2], const int size){
    int index = size - 1;
    if (index == 0) {
        minmax[0] = a[0];
        minmax[1] = a[0];
        return;
    }
    min_max(a, minmax, index);
    if (a[index] < minmax[0])
        minmax[0] = a[index];
    if (a[index] > minmax[1])
        minmax[1] = a[index];
}

//Write a recursive C++ function that converts a string of digits into the integer it represents.
//s is the string to convert, index is the index of the string being processed
int string_to_int(string &s, const u_long index = -1){
    u_long string_index = index - 1;
    if (index == -1)
        return string_to_int(s,s.length());
    if (string_index == 0)
        return (s[string_index] - '0');
    int y = string_to_int(s, string_index);
    int x = s[string_index] - '0';
    x = x * (int)pow(10, string_index) + y;
    return int(x);
}

int main() {
    const int size = 8;
    int a[size] = {85,24,63,45,17,31,96,50};
    cout << "q1" << endl;
    int m = max(a, size);
    cout << m << endl; //prints 96
    m = max2(a,size);
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
