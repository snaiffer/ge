#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void outputArray(short* array, unsigned short& size) {
    cout << " array = [ ";
    for(unsigned short i = 0; i < size; i++)
    cout << array[i] << ", "; 
    cout << "]" << endl;
}

int main(int argc, char const *argv[]){
    unsigned short size = 3;
    cout << "Input size of array = "; cin >> size;
    short* array = new short[size];
    cout << "Input array:" << endl;
    for(unsigned short i = 0; i < size; i++) {
    cout << " array[" << i << "] = "; cin >> array[i];
    }

    cout << "\nInputed array:" << endl;
    outputArray(array, size);
	short n = 5; cout << "Input N = "; cin >> n;

	unsigned short count = 0;
	for(unsigned short i = 0; i < size; i++)
		count += array[i] == n ? 1 : 0;

	cout << "\nN occurrences in inputed array " << count << " times " << endl;

    return 0;
}

