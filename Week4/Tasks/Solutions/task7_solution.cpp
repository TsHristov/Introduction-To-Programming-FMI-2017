// УП-практикум, спец.Информатика, 6-та група, Седмица 4
#include <iostream>
using namespace std;

int main(){
  int number;
  cout << "number=";
  cin  >> number;

  bool prime = true;

  switch(number){
  case 0:
    prime = false;
    break;
  case 1:
    prime = false;
    break;
  }
  
  for(int i=2; i <= number/2; i++){
    if(number % i == 0) prime = false;
  }

  prime? cout << "prime\n" : cout << "not prime\n";

  return 0;
}
