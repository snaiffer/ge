#include <iostream>
using namespace std;

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

  int maxElement = 0;
  int maxIndex = 0;
  for(int i = 0; i < size; i++)
    if (array[i] > maxElement) {
      maxElement = array[i];
      maxIndex = i;
    }

  cout << "\nMax element: " << maxElement << endl;
  cout << "Max element index: " << maxIndex + 1 << endl;
  return 0;
}
