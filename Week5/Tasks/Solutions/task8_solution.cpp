// УП-практикум, спец.Информатика, 6-та група, Седмица 5
#include <iostream>
using namespace std;

const int MAX_TEXT_LENGTH = 7;
const int MAX_SUBSTRING_LENGTH = 4;

void fill_array(char [], const int);
bool check_substring(const char [], const char []);

int main(){
  char text[MAX_TEXT_LENGTH];
  char substring[MAX_SUBSTRING_LENGTH];
  fill_array(text, MAX_TEXT_LENGTH);
  fill_array(substring, MAX_SUBSTRING_LENGTH);

  bool match = check_substring(text, substring);
  cout << "String " << substring << " in " << text << ":";
  (match) ? cout << "Yes\n" : cout << "No\n";

  return 0;
}


// Описание:
//     Проверява дали char масива substring се среща
//     в text.
// Входни параметри на функцията:
//     -const char text[] - указател към char масив
//     -const char substring[] - указател към масив
// Връщан резултат:
//     -true/false - в зависимост от това дали substring се среща в
//                   text
// Кода по-долу има грешка в един конкретен случай, може ли да намерите в кой? :)
bool check_substring(const char text[], const char substring[]){
  // Флаг, който установява първоначална хипотеза за масива.
  // В случая, това е че подниз се среща в дадения масив:
  bool match = true;
  for(int i=0; i<MAX_TEXT_LENGTH; i++){
    // Ако някой от символите в масива съвпада с началото на
    // подниза, то обхождаме и двата едновременно и проверяваме
    // дали и останалите символи съвпадат:
    if(text[i]==substring[0]){
      for(int j=0; j<MAX_SUBSTRING_LENGTH && i<MAX_TEXT_LENGTH; j++, i++){
	if(text[i] != substring[j]){
	  match = false;
	  break;
	}
      }
    }
  }
  return match;
}


void fill_array(char array[], const int array_length){
  cout << "Enter char array's contents (length " << array_length << "):\n";
  for(int i=0; i < array_length; i++){
    cin  >> array[i];
  }
}
