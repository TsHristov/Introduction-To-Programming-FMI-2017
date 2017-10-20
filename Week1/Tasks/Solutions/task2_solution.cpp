#include <iostream>
using namespace std;

int main()
{
  int x, y;
  cout << "x=";
  cin  >> x;
  cout << "y=";
  cin  >> y;

  // Ще използваме тази променлива да съхраняваме
  // конкретната математическа операция:
  char operation;
  cout << "Choose operation from (+, -, *, /, %):";
  cin  >> operation;

  // Според въведената операция,
  // влизаме в определен случай:
  if(operation == '+'){
    cout << "x+y=" << x+y << "\n";
  }
  else if(operation == '-'){
    cout << "x-y=" << x-y << "\n";
  }
  else if(operation == '*'){
    cout << "x*y=" << x*y << "\n";
  }
  else if(operation == '/'){
    if(y == 0){
      cout << "Cannot divide by zero!" << "\n";
    }
    else{
      // Забележете, че тук използваме (double) за да превърнем
      // числата в числа с плаваща запетая, за да можем да получим
      // резултат, който също е число с плаваща запетая.
      // На английски този термин се нарича cast.
      cout << "x/y=" << (double)x/(double)y << "\n";
    }
  }
  else if(operation == '%'){
    cout << "x%y=" << x%y << "\n";
  }
  else{
    cout << "Unrecognized operation!\n";
  }

  return 0;
}
