#include <iostream>
#include <math.h>
using namespace std;

int reverse(int number, int reversed=0){
  if (number == 0) return reversed;
  return reverse(number/10, reversed * 10 + number % 10);
}

int binary(int number, int step=0){
  if (number == 0) return 0;
  return number % 2 * pow(10,step) + binary(number/2, step+1);
}

int main(){
    cout << reverse(1234) << "\n";
    cout << binary(3) << "\n";
    return 0;
}
