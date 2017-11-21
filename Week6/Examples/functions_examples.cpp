// УП-практикум, спец.Информатика, 6-та група, Седмица 6
#include <iostream>
using namespace std;

// Пример за "overloading" на функции, inline
// модификатор, псевдоними, подадени като аргументи
// и параметри по подразбиране:

inline int sum(int x, int y, int z=0);
inline double sum(double x, double y, double z=0);

inline void swap_by_reference(int &x, int &y);
inline void swap_by_value(int x, int y);

int main(){
  int x=1, y=2;
  double a=1.5, b=2.3;

  // Пример за употреба на "overloaded" функции:
  cout << "Sum of integers:\n";
  cout << sum(x, y) << "\n";
  cout << "Sum of doubles:\n";
  cout << sum(a, b) << "\n";

  // Пример за употреба на функции с аргументи по
  // подразбиране. В случая не използваме стойноста по
  // подразбиране 0, а подаваме стойност 1:
  cout << "Sum of integers (overriden default parameter):\n";
  cout << sum(x, y, 1) << "\n";
  cout << "Sum of doubles (overriden default parameter):\n";
  cout << sum(a, b, 1.0) << "\n";
  
  // Извикваме функцията swap_by_value, за размяна на две integer
  // променливи:
  swap_by_value(x, y);

  // Нека видим стойностите на x и y:
  cout << "Using swap_by_value:\n";
  cout << "x=" << x << "\n";
  cout << "y=" << y << "\n";

  // Извикваме функцията swap_by_reference, за размяна на две
  // integer променливи:
  swap_by_reference(x, y);
  cout << "Using swap_by_reference:\n";
  cout << "x=" << x << "\n";
  cout << "y=" << y << "\n";

  return 0;
}

// Описание:
//     Сумира подадените integer аргументи.
//     Последният аргумент е аргумент по подразбиране.
// Входни параметри на функцията:
//     -int x, y - задължителни аргументи
//     -int z    - опционален аргумент
//                 (ако не бъде подаден, стойността му ще бъде 0)
// Връщан резултат:
//     -int sum  - сумата на подадените аргументи на функцията
int sum(int x, int y, int z){
  return x + y + z;
}

// Описание:
//     Сумира подадените double аргументи.
//     Последният аргумент е аргумент по подразбиране.
// Входни параметри на функцията:
//     -double x, y - задължителни аргументи
//     -double z    - опционален аргумент
//                 (ако не бъде подаден, стойността му ще бъде 0)
// Връщан резултат:
//     -double sum  - сумата на подадените аргументи на функцията
double sum(double x, double y, double z){
  return x + y + z;
}

// Описание:
//     Разменя две числа, използвайки псевдоними.
// Странични ефекти:
//     Промените направени във функцията, ще бъдат видими
//     от мястото на извикване на функцията. (Подадените
//     аргументи могат да бъдат променени).
// Входни параметри на функцията:
//     -int &x, &y - псевдоними на integer променливи
void swap_by_reference(int &x, int &y){
  int temp = x;
  x = y;
  y = temp;
}

// Описание:
//     Разменя две числа, използвайки псевдоними.
// Странични ефекти:
//     Промените направени във функцията, НЯМА да бъдат видими
//     от мястото на извикване на функцията. (Подадените
//     аргументи, няма да бъдат променени.)
// Входни параметри на функцията:
//     -int x, y - копия на integer променливи
void swap_by_value(int x, int y){
  int temp = x;
  x = y;
  y = temp;
}
