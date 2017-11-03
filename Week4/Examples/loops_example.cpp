// УП-практикум, спец.Информатика, 6-та група, Седмица 3
// Примерна програма, която демонстрира решаването на един и същ проблем, чрез
// три различни конструкции за итериране - while; do-while; for
// Задачата е да изкараме четните числа в интервала [0, 100] на конзолата.
#include <iostream>
using namespace std;

int main(){
  cout << "Print even numbers in [1, 100] via for: \n";
  for(int i=0; i<=100; i+=2){
    cout << i << ", ";
  }
  cout << "\n";

  cout << "Print even numbers in [1, 100] via while: \n";
  int i = 0;
  while(i<=100){
    cout << i << ", ";
    i += 2;
  }
  cout << "\n";

  cout << "Print even numbers in [1, 100] via do-while: \n";
  i=0; // Реинициализация :)
  do{
    cout << i << ", ";
    i += 2;
  }while(i<=100);
  cout << "\n";
  
  return 0;
}
