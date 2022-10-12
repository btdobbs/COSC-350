#include <iostream>

using namespace std;

//With math, we can remove the loop
int main() {
    int num = 0;
    int odd_count = 0;
    std::cout << "Enter a number: " << endl;
    std::cin >> num;
    if (num % 2 == 0)
        odd_count = num/2;
    else
        odd_count = (num-1)/2;
    std::cout << "The sum of the odd numbers less than " << num
              << " is " << odd_count * odd_count << ".\n";
    return 0;
}
