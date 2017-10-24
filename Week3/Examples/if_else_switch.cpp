// УП-практикум, спец.Информатика, 6-та група, Седмица 3
// Пример за често допускана грешка, при if условия:
#include <iostream>
using namespace std;

int main(){
  int x = 5;
  int y = 4;
  if(x=y){
    cout << x << "=" << y << "\n"; // Не е това което очакваме. Защо?
  }

  // Нека извършим сравнението с тернарния оператор ?:
  (x==y) ? cout << "yes\n" : cout << "no\n";
  
  // Или използвайки switch:
  switch(x){
  case 1:
    cout << "x=1\n";
    break;
  case 2:
    cout << "x=2\n";
    break;
  case 3:
    cout << "x=3\n";
    break;
  case 4:
    cout << "x=4\n";
    break;
  case 5:
    cout << "x=5\n";
    break;
  default:
    cout << "x>5\n";
    break;
  }
  return 0;
}
