// УП-практикум, спец.Информатика, 6-та група, Седмица 6
#include <iostream>
using namespace std;

#define ROWS 2
#define COLUMNS 2

void fill_matrix(int[][COLUMNS]);
void print_matrix(const int[][COLUMNS]);
void max_and_min(const int[][COLUMNS], int&, int&);


int main(){
  int matrix[ROWS][COLUMNS]; 

  fill_matrix(matrix);

  int min, max;
  max_and_min(matrix, min, max);

  print_matrix(matrix);

  cout << "min:" << min << "\n";
  cout << "max:" << max << "\n";

  return 0;
}

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

void max_and_min(const int matrix[][COLUMNS],int &min, int &max){
  min = matrix[0][0];
  max = matrix[0][0];
  for(int i=0; i < ROWS; i++){
    cout << "\n";
    for(int j=0; j < COLUMNS; j++){
      if(max < matrix[i][j]) max = matrix[i][j];
      if(min > matrix[i][j]) min = matrix[i][j];
    }
  }
}





    
