//# used for preprocessor statement or things that are done to a file before it's sent to the c++ compiler
//link in the system library iostream 
#include <iostream>

int main () {
  //link in the user file includeme.cpp
  #include "includeme.cpp"
  //including iostream allows the use of std::cout
  std::cout << "Hello World!\n";
  return 0;
}
