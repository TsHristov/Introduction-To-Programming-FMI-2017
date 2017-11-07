// УП-практикум, спец.Информатика, 6-та група, Седмица 4
#include <iostream>
using namespace std;

int main(){
  int number;
  cout << "number=";
  cin  >> number;

  int reversed = 0;

  while(number){
    reversed = reversed * 10 + number % 10;
    number /= 10;
  }

  cout << "reversed=" << reversed << "\n";

  return 0;
}
