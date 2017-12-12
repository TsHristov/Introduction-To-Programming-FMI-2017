// УП-практикум, спец.Информатика, 6-та група, Седмица 8
#include <iostream>
using namespace std;

// Можем да подаваме аргументи на функция по адрес,
// така не се извършва копиране а се подава само указателя към променливата:
void initialize(int *addr) {
  if (!addr) { cout << "Null pointer passed!\n"; }
  else { *addr = 666; }
}

int main(){
  int variable;
  initialize(&variable);
  initialize(NULL);

  // Извличане на адреса на променливата variable, чрез оператор &:
  cout << "Address of variable: " << &variable << "\n";

  // Извличане на стойността на променливата variable, чрез оператор *:
  cout << "Value of variable: " << *&variable << "\n";

  // Декларация на указател (не оставяйте неинициализирани указатели!) към variable:
  int *pointer = &variable;

  // За по-голяма яснота на концепцията:
  cout << "Address of variable: " << &variable << "\n";
  cout << "Value of pointer to variable: " << pointer << "\n";
  cout << "Value of variable: " << variable << "\n";
  cout << "Value of address pointed by pointer: " << *pointer << "\n"; // Казваме, че дерефенцираме указателя
  cout << "Address of pointer: " << &pointer << "\n"; // Указателите също имат адреси! :)

  int x;
  int * p1 = &x;
  int * p2 = p1;
  *p2 = 24;

  // Какъв ще е изхода от изпълнение на следния ред:
  cout << "x=" << x << "\n";
  return 0;
}
