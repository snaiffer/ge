#include <iostream>
#include <list>
using namespace std;

int main(int argc, char const *argv[]){
  int size = 3;
  cout << "Input size of array = "; cin >> size;
  list<int> array;

  cout << "Input array:" << endl;
  int val;
  for(int i = 0; i < size; i++) {
    cout << " array[" << i << "] = "; cin >> val;
    array.push_back(val);
  }
  cout << "\nInputed array:" << endl;
  for (list<int>::iterator it = array.begin(); it != array.end(); it++) 
    cout << " " << *it ;

  array.remove(0);

  cout << "\nThe array without 0:" << endl;
  for (list<int>::iterator it = array.begin(); it != array.end(); it++) 
    cout << " " << *it ;

  return 0;
}

