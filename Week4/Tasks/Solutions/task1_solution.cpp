// УП-практикум, спец.Информатика, 6-та група, Седмица 4
// Сума и произведение в даден числов интервал [a, b].
#include <iostream>
using namespace std;

int main(){
  int a, b;
  cout << "a=";
  cin >> a;
  cout << "b=";
  cin >> b;

  int sum = 0;
  int product = 1;
  
  for(int i=a; i<=b; i++){
    sum += i;
    product *= i;
  }

  cout << "Sum in [" << a << "," << b << "] = " << sum << "\n";
  cout << "Product in [" << a << "," << b << "] = " << product << "\n";
  
  return 0;
}
