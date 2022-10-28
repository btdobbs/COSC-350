#include <iostream>
#include <cmath>
using namespace std;

void print(const int a[], int size){
    cout << "[";
    for(int i = 0; i < size-1; i++){
        cout << a[i] << ",";
    }
    if (size != 0)
        cout << a[size-1];
    cout << "]" << endl;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

//sum the first n items of an array
int sum(int a[], int n){
    if (n == 1)  //test for base case
        return a[0];
    return sum(a,n-1) + a[n-1]; //recursive step
}

int Fibonacci(int k){
    if (k <= 1)
        return k;
    else
        return Fibonacci(k - 1) + Fibonacci(k - 2);
}

//reverse elements in input array starting with index i and ending at index j
void reverse(int a[], int i, int j){
    if (i < j){
        swap(a[i], a[j]);
        reverse(a, i + 1, j - 1);
    }
    //note, there is no return and the function ends
}

void reverse_iterative(int a[], int i, int j){
    while (i < j){
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

int main() {
    const int item_count = 5;
    int a[item_count] = {1,2,3,4,5};
    print(a, item_count);
    //Recursion
    //1. Identify base case
    //2. Identify sub-problem and recur on the sub-problem
    //Example: In discrete math, a list is an ordered structure with controlled access via head and tail operators
    //l = <2,3,4,5,6>
    //head(l) = 2
    //tail(l) = <3,4,5,6>
    //sum using head and tail of list
    //sum(l) = head(l) + sum(tail(l))

    //Linear Recursion
    //time and memory are proportional to the size of input
    //Linear Recursion with return value
    int s = sum(a,item_count);
    cout << "Sum is " << s << endl;

    //Linear Recursion with no return value
    reverse(a,0,item_count-1);
    print(a, item_count);
    //Tail recursion when recursive call is made on very last operation
    //Tail recursion can be converted to loop
    reverse_iterative(a, 0, item_count-1);
    print(a, item_count);

    //Binary Recursion
    //Two recursive calls in the function
    //memory is proportional to 1 + log_2(n) due to binary tree structure
    //time still proportional to n because we still have n operations to make
    //Binary Recursion with return value
    int f = Fibonacci(10);
    cout << "Sum is " << f << endl;

    //Binary Recursion with no return value
    //discuss next time by revisiting sorting

    //Multiple Recursion
    //More than two recursive calls in the function
    return 0;
}
