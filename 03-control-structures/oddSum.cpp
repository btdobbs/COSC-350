#include <iostream>

using namespace std;

int main () {
    int sum = 0;
    int num = 0;
    std::cout << "Enter a number: " << endl;
    std::cin >> num;
    for (int i = 1; i < num; i+=2){sum+=i;}
    std::cout << "The sum of the odd numbers less than " << num
              << " is " << sum << ".\n";
    return 0;
}
