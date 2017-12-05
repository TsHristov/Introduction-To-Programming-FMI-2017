// УП-практикум, спец.Информатика, 6-та група, Седмица 6
#include <iostream>
using namespace std;

const int ROWS    = 3;
const int COLUMNS = 3;

void fill_matrix(int [][COLUMNS]);
bool scaled(const int [][COLUMNS], const int);

int main(){
  int matrix[ROWS][COLUMNS];

  // Искаме всеки ред от матрицата да е равен на предходния,
  // умножен с дадено число n.
  int n;
  cout << "n=";
  cin  >> n;

  fill_matrix(matrix);

  // Проверяваме дали исканото свойство за матрицата е удоволетворено:
  (scaled(matrix, n)) ? cout << "yes\n" : cout << "no\n";

  return 0;
}


// Описание:
//     Въвежда елементите (по-редове) на дадена матрица.
// Входни параметри на функцията:
//     -int matrix[][COLUMNS] - указател към масив от указатели,
//                              с дължина COLUMNS
void fill_matrix(int matrix[][COLUMNS]){
  cout << "Enter matrix`s contents:\n";
  for(int i=0; i < ROWS; i++){
    for(int j=0; j < COLUMNS; j++){
      cout << "[" << i << "][" << j << "]=";
      cin >> matrix[i][j];
    }
  }
  cout << "\n";
}


// Описание:
//     Проверява дали всеки ред от матрицата е равен на предишния умножен с даден множител n.
// Входни параметри на функцията:
//     -const int matrix[][COLUMNS] - указател към масив от указатели,
//                                    с дължина COLUMNS
//     -const int n - множител
bool scaled(const int matrix[][COLUMNS], const int n){
  bool property = true;
  for(int i=1; i < ROWS; i++){
    for(int j=0; j < COLUMNS; j++){
      if(matrix[i][j] != n * matrix[i-1][j]) property = false;
    }
  }
  return property;
}
