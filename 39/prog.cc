#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void outputArray(int* array, int& size) {
  cout << " array = [ ";
  for(int i = 0; i < size; i++)
    cout << array[i] << ", "; 
  cout << "]" << endl;
}

int main(int argc, char const *argv[]){
  int size = 3;
  cout << "Input size of array = "; cin >> size;
  int* array = new int[size];

  cout << "Input array:" << endl;
  for(int i = 0; i < size; i++) {
    cout << " array[" << i << "] = "; cin >> array[i];
  }

  cout << "\nInputed array:" << endl;
  outputArray(array, size);
	int n = 5; cout << "Input N = "; cin >> n;

	int count = 0;
	for(int i = 0; i < size; i++)
		count += array[i] == n ? 1 : 0;

	cout << "\nN occurrences in inputed array " << count << " times " << endl;

  return 0;
}

