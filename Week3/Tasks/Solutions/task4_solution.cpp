// УП-практикум, спец.Информатика, 6-та група, Седмица 3
#include <iostream>
using namespace std;

int main(){
  int x;
  cout << "x=";
  cin  >> x;

  int bit_position;
  cout << "bit_position=";
  cin  >> bit_position;

  int new_x = x ^ (1<<bit_position);
 
  // Нека x=4, двоичното му представяне е 0100.
  // При bit_postion=0:
  //     1<<0 -> 0001; Имаме 0100 ^ 0001 -> 0101 = 5, така new_x = 5
  // При bit_position=1:
  //     1<<1 -> 0010; Имаме 0100 ^ 0010 -> 0110 = 6, така new_x = 6
  // При bit_position=2:
  //     1<<2 -> 0100; Имаме 0100 ^ 0100 -> 0100 = 4, така new_x = 4
  // При bit_position=3:
  //     1<<3 -> 1000; Имаме 0100 ^ 1000 -> 1100 = 12, така new_x = 12

  cout << "x=" << x << " with set bit at position " \
       << bit_position << " equals " << new_x << "\n";
                
  return 0;
}
