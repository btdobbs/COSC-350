#include <cstdlib>
#include <iostream>

int main() {
  // Seed the random number generator
  srand((unsigned)time(NULL));

  // create a random number between 0 and 9 (i.e. max-1)
  int max = 10;
  int num = rand() % max;
  std::cout << num;
  std::cout << "\n\n";

  // create ten random nubmers between 65 and 122 (readable char numbers)
  max = 122;
  int min = 65;
  int range = max - min + 1;
  for (int i = 0; i < 10; i++) {
    std::cout << (char)(rand() % range + min);
  }
  std::cout << "\n";
}
