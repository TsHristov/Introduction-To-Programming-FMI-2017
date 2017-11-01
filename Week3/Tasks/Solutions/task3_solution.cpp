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

  if (bit_position < 0){
    cout << "bit_position must be positive!";
  }

  // Нека x = 5 (0101)
  // Операцията 1<<n, премества битовете на едно число n позиции наляво, запълвайки ги с 0-ли:
  //     n=1: 0001 << 1 -> 0010
  //     n=2: 0001 << 2 -> 0100
  // Решението на задачата използва << по следния начин:
  // При bit_position = 0:
  //     1<<0 -> 0001; Имаме 0101 & 0001 -> 0001 != 0 => бита на позиция 0 в 5 e 1
  // При bit_position = 1:
  //     1<<1 -> 0010; Имаме 0101 & 0010 -> 0000 == 0 => бита на позиция 1 в 5 е 0
  // При bit_position = 2:
  //     1<<2 -> 0100; Имаме 0101 & 0100 -> 0100 != 0 => бита на позиция 2 в 5 е 1 

  if(x & (1<<bit_position)){
    cout << "bit is set (not equal to 1)\n";
  } else {
    cout << "bit is not set (not equal to 1)\n";
  }
  
  return 0;
}
