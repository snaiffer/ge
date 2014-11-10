#include <iostream>
#include <cstring>
#include <ctime>
#include <exception>
#include <string>

#include <fstream>
#include <sstream>

void funcThatExpectsCstring(char* str)       { std::cout << str;}
void funcThatExpectsCstring(const char* str) {std::cout << str;}


#define DISTINCT 10
using namespace std;

struct stringException : public exception {
  const char * what () const throw () {
    return "String Exception";
  }
};

struct cantfind_substr : public stringException {
  const char * what () const throw () {
    return "Can't find substr in current string";
  }
};

class String {
  char* str;
  int len;
  char* creationTime;

  void fillin_creationTime() {
     time_t now = time(0); // current date/time based on current system
     creationTime = ctime(&now); // convert now to string form
  }

public:  
  String(const char* string = "") {
    str = 0; len = 0;
    fillin_creationTime();
    set_str(string);
  }

  // copy constructor
  String(const String &string) {
    str = 0; len = 0;
    fillin_creationTime();
    set_str(string.get_str());
    len = string.get_len();
  }

  char* get_str() const { return str; }
  int get_len() const { return len; }
  char* get_creationTime() const { return creationTime; }

  void set_str(const char* string) {
    int newlen = strlen(string) + 1;  // with null char
    // Change size to more size in any case and to less one in case of big distinction
    if (newlen > len || newlen < (len - DISTINCT)) {
      delete[] str; str = 0;
      str = new char[newlen];
      len = newlen;
    }
    copy(string, string+newlen, str);
  }

  String& operator= (const String &string) {
    // check for self-assignment by comparing the address of the
    // implicit object and the parameter
    if (this == &string)
        return *this;

    set_str(string.get_str());
 
    return *this;
  }
  String& operator= (const char* string) {
    set_str(string);
 
    return *this;
  }

  int find_substr(const char* substr) {
    for (int i = 0; i < len-1; i++) 
      if (str[i] == substr[0]) {
        int j;
        for (j = 0; substr[j] != '\0'; j++) 
          if (str[i+j] != substr[j])
            break;
        if (substr[j] == '\0') 
          return i+1;
        }
    throw cantfind_substr();
  }

  ~String() {
    if (str) {
      delete[] str; str = 0;
    }
  }
};

ostream &operator << (ostream &out, const String &str) {
  out << str.get_str();
  return out;
}

istream& operator>> (istream &in, String &str) {
  string inputted;
  getline(in, inputted);
  getline(in, inputted);
  str.set_str(inputted.c_str());

  return in;
}

int main(int argc, char const *argv[]){
  /*
  String str("hello");
  cout << str.get_creationTime() << endl;
  cout << str.get_len() << endl;
  cout << str << endl;

  String str2("hello");
  String str3(str);
  str = str3;

  str = "hello";
  cout << endl;
  cout << str << endl;
  try {
    cout << "Index of substr in str: " << str.find_substr("llo") << endl;
  }
  catch(cantfind_substr e) {
    cout << e.what() << endl;
  } 
  */


  String str("hello");

  cout << "List of commands:" << endl;
  cout << "\t input" << endl;
  cout << "\t output" << endl;
  cout << "\t outlen" << endl;
  cout << "\t find" << endl;
  cout << "\t quite" << endl;
  cout << endl;

  bool quite = false;
  string cmd = "";
  while (! quite) {
    cout << "Input command: ";
    cin >> cmd;

    if (cmd == "input" || cmd == "in") {
      cout << " Input string: "; cin >> str;
    } else if ( cmd == "output" || cmd == "out") {
      cout << str << endl;
    } else if ( cmd == "outlen") {
      cout << " Lenght of the string = " << str.get_len() << endl;
    } else if ( cmd == "find") {
      string substr; 
      cout << " Input substring which you want to find in the inputted string: "; cin >> substr;
      try {
        cout << " Index of substr in the string = " << str.find_substr(substr.c_str()) << endl;
      }
      catch(cantfind_substr e) {
        cout << e.what() << endl;
      } 
      
    } else if ( cmd == "quite" || cmd == "q") {
      quite = true;
      cout << "exit" << endl;
    } else {
      cout << " Unknown command!" << endl;
    }
  }
  return 0;
}

