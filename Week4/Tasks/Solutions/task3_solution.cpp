// УП-практикум, спец.Информатика, 6-та група, Седмица 4
#include <iostream>
using namespace std;

int main(){
  int number;
  cout << "number=";
  cin  >> number;

  cout << "number`s digits (reversed): ";
  while(number){
    cout << number % 10 << " ";
    number /= 10;
  }
  cout << "\n";
  
  return 0;
}
