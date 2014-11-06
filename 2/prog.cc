#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

class Directory {
  typedef map<string, string> strmap;
  strmap direct;

public: 
  Directory() {}

  void insert(string phone, string name) {
    direct.insert(map<string, string>::value_type(phone, name));
  }

  void output() {
    cout << "Contents of the directory:" << endl;
    cout << setw(25) << " phone " << " | " << setw(15) << " name " << endl;
    strmap::const_iterator iter;
    for (iter = direct.begin(); iter != direct.end(); iter++) {
      cout << setw(25) << (*iter).first << " | " << setw(15) << (*iter).second << endl;
    }
  }

  void findby_phone(const string phone) {
    strmap::const_iterator pos = direct.find(phone);
    if (pos == direct.end())
      cout << "Can't find any records" << endl;
    else
      cout << "Find: \n\t" << (*pos).second << endl;
  }

  void findby_name(const string name) {
    bool result = false;
    cout << "Find: " << endl;
    strmap::const_iterator iter;
    for (iter = direct.begin(); iter != direct.end(); iter++) 
      if ( (*iter).second == name ) {
        cout << "\t" << (*iter).first << endl;
        result = true;
      }

    if (! result)  
      cout << "Can't find any records" << endl;
  }
};


int main() {
  Directory direct;

  //default
  direct.insert("89262624847", "Alex");
  direct.insert("89035621111", "Alex");
  direct.insert("+11231231212", "Tylor");
  direct.insert("+7 (905) 567-58-34", "Vika");

  cout << "List of commands:" << endl;
  cout << "\t output" << endl;
  cout << "\t insert" << endl;
  cout << "\t findby_name" << endl;
  cout << "\t findby_phone" << endl;
  cout << "\t quite" << endl;
  cout << endl;

  bool quite = false;
  string cmd = "";
  while (! quite) {
    cout << "Input command: ";
    cin >> cmd;

    if (cmd == "output") {
      direct.output();
    } else if ( cmd == "insert") {
      string name; cout << "\n Input name: "; cin >> name;
      string phone; cout << " Input phone: "; cin >> phone;
      direct.insert(phone, name);
    } else if ( cmd == "findby_name") {
      string name; cout << " Input name: "; cin >> name;
      direct.findby_name(name);
    } else if ( cmd == "findby_phone") {
      string phone; cout << " Input phone: "; cin >> phone;
      direct.findby_phone(phone);
    } else if ( cmd == "quite") {
      quite = true;
      cout << "exit" << endl;
    } else {
      cout << "Unknown command!" << endl;
    }
  }

  return 0;
}

