#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
  int** matrix;
  int order;

  void set_order(int ord = 0) {
    matrix = new int*[ord];
    for(int i=0; i < ord; i++)
      matrix[i] = new int[ord];
    order = ord;
  }

public:
  Matrix(int ord) {
    matrix = 0;
    set_order(ord);
  }

  int get_order() const { return order; }

  void input() {
    cout << "Input matrix:" << endl;
    for(int i = 0; i < order; i++)
      for(int j = 0; j < order; j++) {
        cout << " matrix[" << i << "][" << j << "] = "; cin >> matrix[i][j];
      }
  }

  void output() {
    for(int i = 0; i < order; i++) {
      for(int j = 0; j < order; j++)
        cout << setw(5) << matrix[i][j];
      cout << endl;
    }
  }

  void bufferSwap (int &x, int &y) {
    int temp = y;
    y = x;
    x = temp;
  }

  void transp() {
    for(int diag = 0; diag < (order-1); diag++) 
      for(int j = diag + 1; j < order; j++) 
        bufferSwap(matrix[j][diag], matrix[diag][j]);
  }

  ~Matrix() {
    for(int i=0; i < order; i++)
      delete[] matrix[i];
    delete[] matrix;
  }
};

int main(int argc, char const *argv[]){
  int order = 0;
  cout << "Input order of a matrix = "; cin >> order;
  Matrix matrix(order);
  matrix.input();

  cout << "List of commands:" << endl;
  cout << "\t output" << endl;
  cout << "\t transp" << endl;
  cout << "\t outorder" << endl;
  cout << "\t quite" << endl;
  cout << endl;

  bool quite = false;
  string cmd = "";
  while (! quite) {
    cout << "Input command: ";
    cin >> cmd;

    if (cmd == "output" || cmd == "out") {
      matrix.output();
    } else if ( cmd == "transp") {
      matrix.transp();
      cout << "Transporting matrix:" << endl;
      matrix.output();
    } else if ( cmd == "outorder") {
      cout << "Order of the matrix = " << matrix.get_order() << endl;
    } else if ( cmd == "quite" || cmd == "q") {
      quite = true;
      cout << "exit" << endl;
    } else {
      cout << "Unknown command!" << endl;
    }
  }

  return 0;
}

