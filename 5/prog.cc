#include <iostream>
using namespace std;

#define NUM 8

int main() {
  int F = 1;
  for (int i=2; i <= NUM; i++) 
    F *= i;
  cout << NUM << "! = " << F << endl;  

  return 0;
}

