#include <iostream>
using namespace std;

class Stack {
  struct Element {
    int value;
    Element* prev;

    Element(int val) {
      value = val;
      prev = 0;
    }
  };
  Element* bottom;
  Element* top;

public:  
  Stack() {
    bottom = 0;
    top = 0;
  }

  void push(int val) {
    Element* newel = new Element(val);
    if ( bottom )
      newel->prev = top;
    else
      bottom = newel;
    top = newel;
  }
  
  int pop() {
    int res = top->value;
    Element* oldfront = top;
    top = top->prev;
    if (! top) 
      bottom = 0;
    delete[] oldfront;
    return res;
  }

  bool empty() {
    if (top) 
      return false;
    else 
      return true;
  }

  ~Stack() {
    while (! empty())
      pop();
  }
};

int main() {
  Stack stack;

  //default
  stack.push(1);
  stack.push(2);

  cout << "List of commands:" << endl;
  cout << "\t push" << endl;
  cout << "\t pop" << endl;
  cout << "\t quite" << endl;
  cout << endl;

  bool quite = false;
  string cmd = "";
  while (! quite) {
    cout << "Input command: ";
    cin >> cmd;

    if (cmd == "pop") {
      if (! stack.empty() )
        cout << " " << stack.pop() << endl;
      else
        cout << "The stack is empty!" << endl;
    } else if ( cmd == "push" ) {
      int val; cout << " Input value: "; cin >> val;
      stack.push(val);
    } else if ( cmd == "quite" || cmd == "q" || cmd == "exit") {
      quite = true;
      cout << "exit" << endl;
    } else {
      cout << "Unknown command!" << endl;
    }
  }

  return 0;
}

