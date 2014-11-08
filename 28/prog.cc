#include <iostream>
using namespace std;

void outputArray(short* array, unsigned short& size) {
  cout << " array = [ ";
  for(unsigned short i = 0; i < size; i++)
    cout << array[i] << ", "; 
  cout << "]" << endl;
}

int main() {
  unsigned short size = 3;
  cout << "Input size of array = "; cin >> size;
  short* array = new short[size];

  cout << "Input array:" << endl;
  for(unsigned short i = 0; i < size; i++) {
    cout << " array[" << i << "] = "; cin >> array[i];
  }
  cout << "\nInputed array:" << endl;
  outputArray(array, size);
  int maxElement = 0;
  int maxIndex = 0;
  for(unsigned short i = 0; i < size; i++)
    if (array[i] > maxElement) {
      maxElement = array[i];
      maxIndex = i;
    }
    // maxElement = array[i] > maxElement ? array[i] : maxElement;
  cout << "\nMax element: " << maxElement << endl;
  cout << "\nMax element index: " << maxIndex + 1 << endl;
  return 0;
}

/*
 * word type: 2 bytes, 0..65535
 * unsigned short in C++ is the same as word in Pascal
 */
