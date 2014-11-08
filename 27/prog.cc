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

void reverseArray(short* array, unsigned short& size){
    int a;
    for(unsigned short i = 0, j=size - 1; i < j; i++, j--){
        a = array[i];
        array[i] = array[j];
        array[j] = a;
    }
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
    reverseArray(array, size);
    cout << "\nRerversed array:" << endl;
    outputArray(array, size);
    return 0;
}

