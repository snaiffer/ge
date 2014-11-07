#include <iostream>
#include <string>
using namespace std;

class Dict {
  struct Element {
    int key;
    string val;
    Element(int k=0, string v="") {
      key = k;
      val = v;
    }
  };
  Element* array;
  int size;

public:
  Dict() {
    array = 0;
    size = 0;
  }

  string& operator[] (const int key) {
    // try to find value with such key
    for(int i=0; i < size; i++) 
      if (array[i].key == key) 
        return array[i].val;

    // create new value if can't find 
    
    // realloc (extend array)
    Element* temp = new Element[size+1];
    copy(array, array + size, temp);
    delete[] array;
    array = temp;
    ++size;

    array[size-1].key = key;
    array[size-1].val = "";
    return array[size-1].val;
  }

  ~Dict() {
    delete[] array;
    array = 0;
  }
};

int main() {
  Dict dict;

  cout << "List of commands:" << endl;
  cout << "\t insert" << endl;
  cout << "\t output" << endl;
  cout << "\t quite" << endl;
  cout << endl;

  bool quite = false;
  string cmd = "";
  while (! quite) {
    cout << "Input command: ";
    cin >> cmd;

    if (cmd == "insert" || cmd == "in") {
      int key; cout << " Input key: "; cin >> key;
      string val; cout << " Input value: "; cin >> val;
      dict[key] = val;
    } else if ( cmd == "output" || cmd == "out") {
      int key; cout << " Input key: "; cin >> key;
      cout << "Value by key(" << key << ") = " << dict[key] << endl; 
    } else if ( cmd == "quite" || cmd == "q" || cmd == "exit") {
      quite = true;
      cout << "exit" << endl;
    } else {
      cout << "Unknown command!" << endl;
    }
  }
  return 0;
}
