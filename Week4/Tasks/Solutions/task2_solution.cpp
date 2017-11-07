// УП-практикум, спец.Информатика, 6-та група, Седмица 4
// Проверка за монотонно растяща редица:
#include <iostream>
using namespace std;

int main(){
  int size;
  cout << "size=";
  cin  >> size;
  
  int previous = 0;
  int current  = 0;
  bool flag    = true;
  
  for(int i=0; i < size; i++){
    cin >> current;
    if (previous > current) flag = false;
    previous = current;
  }

  flag ? cout << "yes\n" : cout << "no\n";
  
  return 0;
}
