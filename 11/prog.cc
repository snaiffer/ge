#include <iostream>
using namespace std;

void outputArray(unsigned short* array, unsigned short& size) {
  cout << " array = [ ";
  for(unsigned short i = 0; i < size; i++)
    cout << array[i] << ", "; 
  cout << "]" << endl;
}

int main() {
  unsigned short size = 3;
  cout << "Input size of array = "; cin >> size;
  unsigned short* array = new unsigned short[size];

  cout << "Input array:" << endl;
  for(unsigned short i = 0; i < size; i++) {
    cout << " array[" << i << "] = "; cin >> array[i];
  }
  cout << "\nInputed array:" << endl;
  outputArray(array, size);
  unsigned short m = 5; cout << "Input m = "; cin >> m;

  unsigned long sum = 0;
  for(unsigned short i = 0; i < size; i++)
    if ( array[i] < m )
      sum += array[i];
  cout << "\nSum of elements < " << m << " = " << sum << endl; 

  return 0;
}

/*
 * word type: 2 bytes, 0..65535
 * unsigned short in C++ is the same as word in Pascal
 */
