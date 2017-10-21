#include <iostream>
using namespace std;

int main()
{
  int x, y;
  cout << "x=";
  cin  >> x;
  cout << "y=";
  cin  >> y;
  // Нека вземем за пример x=5 (0101)
  // и y=4 (0100)
  x = x ^ y; // x = 0101 ^ 0100 = 0001
  y = x ^ y; // y = 0001 ^ 0100 = 0101
  x = x ^ y; // x = 0001 ^ 0101 = 0100
  // Вече x=4 и y=5 :)
  cout << "x=" << x << "\n";
  cout << "y=" << y << "\n";
  return 0;
}
