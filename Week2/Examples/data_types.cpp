// УП-практикум, спец.Информатика, 6-та група, Седмица 2
// Основни типове данни и техният размер (горната граница зависи от хардуера):
//        -Тип char - представляват един символ (например 'a', '.' и т.н.)
//        -Тип int - целочислени числа:
//            - signed (със знак)   - поддържат както отрицателни, така и положителни стойности
//            - unsigned (без знак) - поддържат само положителни стойности
//        -Тип float, double - реални числа с "плаваща" запетая:
//            - float
//            - double
//        -Тип bool - булеви стойности - True/False

#include <iostream>
using namespace std;

int main()
{
  cout << "--------------------\n";
  cout << "Size of data types (in bytes):\n";
  cout << "2.Integer types(signed):\n";
  cout << "Size of signed char: "               << sizeof(signed char)        << " bytes\n";
  cout << "Size of (signed) short (int): "      << sizeof(short)              << " bytes\n";
  cout << "Size of (signed) int: "              << sizeof(int)                << " bytes\n";
  cout << "Size of (signed) long (int): "       << sizeof(long)               << " bytes\n";
  cout << "Size of (signed) long long (int): "  << sizeof(long long)          << " bytes\n\n";
  cout << "3.Integer types (unsigned):\n";
  cout << "Size of unsigned char: "             << sizeof(unsigned char)      << " bytes\n";
  cout << "Size of unsigned short (int): "      << sizeof(unsigned short)     << " bytes\n";
  cout << "Size of unsigned (int): "            << sizeof(unsigned)           << " bytes\n";
  cout << "Size of unsigned long (int): "       << sizeof(unsigned long)      << " bytes\n";
  cout << "Size of unsigned long long (int): "  << sizeof(unsigned long long) << " bytes\n\n";
  cout << "4.Floating-point types:\n";
  cout << "Size of float: "                     << sizeof(float)              << " bytes\n";
  cout << "Size of double: "                    << sizeof(double)             << " bytes\n";
  cout << "Size of long double: "               << sizeof(long double)        << " bytes\n\n";
  cout << "5.Boolean type:\n";
  cout << "Size of bool: "                      << sizeof(bool)               << " bytes\n\n";
  cout << "--------------------\n";
  return 0;
}
