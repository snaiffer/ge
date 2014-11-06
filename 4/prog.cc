#include <iostream>
using namespace std;

int main() {
  int n = 0;
  cout << "n = "; cin >> n;
  int S = 0;
  for (int i=1; i <= n; i++) 
    S += i;
  cout << "Sum = " << S << endl;  

  return 0;
}

