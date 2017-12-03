// УП-практикум, спец.Информатика, 6-та група, Седмица 6
#include <iostream>
using namespace std;

const int ROWS    = 3;
const int COLUMNS = 3;

void fill_matrix(int [][COLUMNS]);
void print_matrix(const int [][COLUMNS]);
int elements_product(const int [][COLUMNS]);
int elements_sum(const int [][COLUMNS]);

int main(){
  int matrix[ROWS][COLUMNS];
  fill_matrix(matrix);
  print_matrix(matrix);
  // Помислете как можем да намерим сумата и произведението
  // с едно обхождане на матрицата. Най-вече как ще върнем
  // резултата от функцията (сумата и произведението)?
  cout << "Elements sum: " << elements_sum(matrix) << "\n";
  cout << "Elements product: " << elements_product(matrix) << "\n";
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
//     Изкарва елементите на даден масив (обхождайки ги по редове) на конзолата.
// Входни параметри на функцията:
//     -const int matrix[][COLUMNS] - указател към масив от указатели,
//                                    с дължина COLUMNS
void print_matrix(const int matrix[][COLUMNS]){
  cout << "Matrix`s contents (by rows):\n";
  for(int i=0; i < ROWS; i++){
    cout << "\n";
    for(int j=0; j < COLUMNS; j++){
      cout << "[" << i << "][" << j << "]=" \
	   << matrix[i][j] << " ";
    }
  }
  cout << "\n";
}


// Описание:
//     Намира произведението на всички елементи в дадена матрица.
// Входни параметри на функцията:
//     -const int matrix[][COLUMNS] - указател към масив от указатели,
//                                    с дължина COLUMNS
int elements_product(const int matrix[][COLUMNS]){
  int product = 1;
  for(int i=0; i < ROWS; i++){
    for(int j=0; j < COLUMNS; j++){
      product *= matrix[i][j];
    }
  }
  return product;
}


// Описание:
//     Намира сумата на всички елементи в дадена матрица.
// Входни параметри на функцията:
//     -const int matrix[][COLUMNS] - указател към масив от указатели,
//                                    с дължина COLUMNS
int elements_sum(const int matrix[][COLUMNS]){
  int sum = 0;
  for(int i=0; i < ROWS; i++){
    for(int j=0; j < COLUMNS; j++){
      sum += matrix[i][j];
    }
  }
  return sum;
}
