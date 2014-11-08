#include <iostream>
using namespace std;

void xorSwap (int *x, int *y) {
 if (x != y) {
   *x ^= *y;
   *y ^= *x;
   *x ^= *y;
 }
}

void bufferSwap (int *x, int *y) {
  int temp = *y;
  *y = *x;
  *x = temp;
}

void outputArray(int* array, int& size) {
  cout << " array = [ ";
  for(int i = 0; i < size; i++)
    cout << array[i] << ", "; 
  cout << "]" << endl;
}

int main() {
  int size = 3;
  cout << "Input size of array = "; cin >> size;
  int* array = new int[size];

  cout << "Input array:" << endl;
  for(int i = 0; i < size; i++) {
    cout << " array[" << i << "] = "; cin >> array[i];
  }
  cout << "\nInputed array:" << endl;
  outputArray(array, size);

  for(int left = 0, right = size - 1; left < size/2; left++, right--)
    xorSwap(&array[left], &array[right]);
  cout << "\nReverted with XOR:" << endl;
  outputArray(array, size);
  
  for(int left = 0, right = size - 1; left != right; left++, right--)
    bufferSwap(&array[left], &array[right]);
  cout << "\nReverted the reverted array with buffer:" << endl;
  outputArray(array, size);

  return 0;
}

/*
XOR:
a= 1010
b= 0011

a= 1001
b= 1010
a= 0011
*/
