// УП-практикум, спец.Информатика, 6-та група, Седмица 6
#include <iostream>
using namespace std;

const int ROWS    = 3;
const int COLUMNS = 3;

void fill_matrix(int [][COLUMNS]);
void print_matrix_by_rows(const int [][COLUMNS]);
void print_matrix_by_columns(const int [][COLUMNS]);

int main(){
  int matrix[ROWS][COLUMNS];
  fill_matrix(matrix);
  print_matrix_by_rows(matrix);
  print_matrix_by_columns(matrix);
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
void print_matrix_by_rows(const int matrix[][COLUMNS]){
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
//     Изкарва елементите на даден масив (обхождайки ги по колони) на конзолата.
// Входни параметри на функцията:
//     -const int matrix[][COLUMNS] - указател към масив от указатели,
//                                    с дължина COLUMNS
void print_matrix_by_columns(const int matrix[][COLUMNS]){
  cout << "Matrix`s contents (by columns):\n";
  for(int i=0; i < ROWS; i++){
    cout << "\n";
    for(int j=0; j < COLUMNS; j++){
      cout << "[" << j << "][" << i << "]=" \
	   << matrix[j][i] << " ";
    }
  }
  cout << "\n";
}
