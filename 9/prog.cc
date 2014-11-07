#include <iostream>
using namespace std;


class Queue {
  struct Element {
    int value;
    Element* prev;

    Element(int val) {
      value = val;
      prev = 0;
    }
  };
  Element* back;
  Element* front;

public:  
  Queue() {
    back = 0;
    front = 0;
  }

  void push_back(int val) {
    Element* newel = new Element(val);
    if ( back )
      back->prev = newel;
    else
      front = newel;
    back = newel;
  }
  
  int pop_front() {
    int res = front->value;
    Element* oldfront = front;
    front = front->prev;
    if (! front) 
      back = 0;
    delete[] oldfront;
    return res;
  }

  bool empty() {
    if (front) 
      return false;
    else 
      return true;
  }

  ~Queue() {
    while (! empty())
      pop_front();
  }
};


int main() {
  Queue queue;

  //default
  queue.push_back(1);
  queue.push_back(2);

  cout << "List of commands:" << endl;
  cout << "\t push_back" << endl;
  cout << "\t pop_front" << endl;
  cout << "\t quite" << endl;
  cout << endl;

  bool quite = false;
  string cmd = "";
  while (! quite) {
    cout << "Input command: ";
    cin >> cmd;

    if (cmd == "pop_front" || cmd == "pop") {
      if (! queue.empty() )
        cout << " " << queue.pop_front() << endl;
      else
        cout << "The queue is empty!" << endl;
    } else if ( cmd == "push_back" || cmd == "push") {
      int val; cout << " Input value: "; cin >> val;
      queue.push_back(val);
    } else if ( cmd == "quite" || cmd == "q" || cmd == "exit") {
      quite = true;
      cout << "exit" << endl;
    } else {
      cout << "Unknown command!" << endl;
    }
  }

  return 0;
}

