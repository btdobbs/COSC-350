#include <iostream>
#include <string>

using namespace std;

enum color {black, white, red, blue, none};

color getColor(char c)
{
  switch (c)
    {
      case 'b':
        return black;
      case 'w':
        return white;
      case 'r':
        return red;
      case 'l':
        return blue;
      default:
        return none;
    }
}


color getColor(int c)
{
  switch (c)
    {
      case 0:
        return black;
      case 1:
        return white;
      case 2:
        return red;
      case 3:
        return blue;
      default:
        return none;
    }
}

string getColor(color c)
{
  switch (c)
    {
      case black:
        return "black";
      case white:
        return "white";
      case red:
        return "red";
      case blue:
        return "blue";
      default:
        return "none";
    }
}

int main() {
  color c = none;
  char charColor;
  short shortColor;
  
  std::cout << "Enter a color: (b)lack, (w)hite, (r)ed, b(l)ue\n";
  std::cin >> charColor;
  std::cout << getColor(charColor) << endl;
  std::cout << getColor(getColor(charColor)) << endl;
  std::cout << "Enter a color: 0-black, 1-white, 2-red, 3-blue\n";
  std::cin >> shortColor;
  std::cout << getColor(shortColor) << endl;
}
