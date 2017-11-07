// УП-практикум, спец.Информатика, 6-та група, Седмица 4
#include <iostream>
using namespace std;

int main(){
  int number;
  cout << "number=";
  cin  >> number;

  cout << "number`s divisors: ";
  for(int i=1; i<=number; i++){
    if(number%i == 0) cout << i << " ";
  }
  cout << "\n";
  return 0;
}
