// УП-практикум, спец.Информатика, 6-та група, Седмица 6
#include <iostream>
using namespace std;

const int ROWS    = 3;
const int COLUMNS = 3;

void fill_matrix(int [][COLUMNS]);
void print_matrix(const int [][COLUMNS]);
void print_column(const int [][COLUMNS], const int);
void print_row(const int [][COLUMNS], const int);
int column_product(const int[][COLUMNS], const int);
int row_sum(const int [][COLUMNS], const int);
int max_sum_row(const int [][COLUMNS]);
int max_product_column(const int[][COLUMNS]);

int main(){
  int matrix[ROWS][COLUMNS];
  fill_matrix(matrix);
  print_matrix(matrix);

  // Получаваме индекса на реда с най-голяма сума:
  int max_row_index = max_sum_row(matrix);
  cout << "Max sum row index: " << max_row_index << "\n";
  cout << "Max sum row content: ";
  // Изкарваме на конзолата реда с най-голяма сума:
  print_row(matrix, max_row_index);

  // Получаваме индекса на колоната с най-голямо произведение:
  int max_column_index = max_product_column(matrix);
  cout << "Max product column index: " << max_column_index << "\n";
  cout << "Max product column content: ";
  // Изкарваме на конзолата колоната с най-голямо произведение:
  print_column(matrix, max_column_index);
  
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
//     Изкарва елементите на дадена матрица (обхождайки ги по редове) на конзолата.
// Входни параметри на функцията:
//     -const int matrix[][COLUMNS] - указател към масив от указатели,
//                                    с дължина COLUMNS
void print_matrix(const int matrix[][COLUMNS]){
  cout << "Matrix`s contents:\n";
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
//     Изкарва на конзолата конкретна колона от матрица.
// Входни параметри на функцията:
//     -const int matrix[][COLUMNS] - указател към масив от указатели,
//                                    с дължина COLUMNS
//     -const int column - индекс на колоната
void print_column(const int matrix[][COLUMNS], const int column){
  for(int i=0; i<ROWS; i++){
    cout << matrix[i][column] << " ";
  }
  cout << "\n";
}


// Описание:
//     Изкарва на конзолата конкретен ред от матрица.
// Входни параметри на функцията:
//     -const int matrix[][COLUMNS] - указател към масив от указатели,
//                                    с дължина COLUMNS
//     -const int row - индекс на реда
void print_row(const int matrix[][COLUMNS], const int row){
  for(int i=0; i<COLUMNS; i++){
    cout << matrix[row][i] << " ";
  }
  cout << "\n";
}


// Описание:
//     Намира произведението на елементите на конкретна колона от матрица.
// Входни параметри на функцията:
//     -const int matrix[][COLUMNS] - указател към масив от указатели,
//                                    с дължина COLUMNS
//     -const int column - индекс на колоната
int column_product(const int matrix[][COLUMNS], const int column){
  int product = 1;
  for(int i=0; i < ROWS; i++){
    product *= matrix[i][column];
  }
  return product;
}


// Описание:
//     Намира сумата на елементите на конкретен ред от матрица.
// Входни параметри на функцията:
//     -const int matrix[][COLUMNS] - указател към масив от указатели,
//                                    с дължина COLUMNS
//     -const int column - индекс на реда
int row_sum(const int matrix[][COLUMNS], const int row){
  int sum = 0;
  for(int i=0; i < COLUMNS; i++){
    sum += matrix[row][i];
  }
  return sum;
}


// Описание:
//     Намира индекса на реда с най-голяма сума.
// Входни параметри на функцията:
//     -const int matrix[][COLUMNS] - указател към масив от указатели,
//                                    с дължина COLUMNS
int max_sum_row(const int matrix[][COLUMNS]){
  int max_sum     = -1;
  int row_index   = -1;
  int current_row_sum = -1;
  for(int i=0; i < ROWS; i++){
    current_row_sum = row_sum(matrix, i);
    if(current_row_sum > max_sum){
      max_sum = current_row_sum;
      row_index   = i;
    }
  }
  return row_index;
}


// Описание:
//     Намира индекса на колоната с най-голямо произведение.
// Входни параметри на функцията:
//     -const int matrix[][COLUMNS] - указател към масив от указатели,
//                                    с дължина COLUMNS
int max_product_column(const int matrix[][COLUMNS]){
  int max_product  = -1;
  int column_index = -1;
  int current_column_product = -1;
  for(int i=0; i < COLUMNS; i++){
    current_column_product = column_product(matrix, i);
    if(current_column_product > max_product){
      max_product = current_column_product;
      column_index = i;
    }
  }
  return column_index;
}
