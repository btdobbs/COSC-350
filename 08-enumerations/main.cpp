#include <iostream>

using namespace std;

int main ()
{
  //enum associates a user friendly value that can be used in code
  //first value defaults to 0 and subsequent values are incremented by 1
  enum weekend {saturday, sunday};
  //you can force the first value to be a specific number and subsequent values are incremented by 1
  //Note, numbers can be negative but they can not collide.  Forexample, setting A to 9 would generate a compile error
  enum test {A = -2, B, C};
  cout << A << "\n";
  cout << B << "\n";
  enum TestType {A=3,B,C,D=10,E,F};
  for(int i = 0; i<15; i++)
  {
    switch ((TestType)i)
    {
      case A:
        cout << "A=i=" << i << "\n";
        break;
      case B:
        cout << "B=i=" << i << "\n";
        break;
      case C:
        cout << "C=i=" << i << "\n";
        break;
      case D:
        cout << "D=i=" << i << "\n";
        break;
      case E:
        cout << "E=i=" << i << "\n";
        break;
      case F:
        cout << "F=i=" << i << "\n";
        break;
      default:
        cout << "default=i=" << i << "\n";
        break;
    }
  }
  return 0;
}
