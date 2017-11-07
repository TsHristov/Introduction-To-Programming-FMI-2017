// УП-практикум, спец.Информатика, 6-та група, Седмица 4
#include <iostream>
using namespace std;

int main(){
  int number;
  cout << "number=";
  cin  >> number;

  int factorial = 1;
  for(int i=1; i <= number; i++){
    factorial *= i;
  }

  cout << "number!=" << factorial << "\n";
  return 0;
}
