#include <iostream>
#include <ctime>

#define DISTINCT 10
using namespace std;

class String {
  char* str;
  int len;
  char* creationTime;

  void fillin_creationTime() {
     time_t now = time(0); // current date/time based on current system
     creationTime = ctime(&now); // convert now to string form
  }

  void newStr(const char* string) {
    int newlen = sizeof(string);
    if (newlen > len || newlen < (len - DISTINCT)) {
      delete[] str;
      str = new char[newlen];
      len = newlen;
      //str = string;
    }
  }
public:  
  String(char* string) {
    fillin_creationTime();
    str = string;
  }

  int get_len() const { return len; }
  char* get_creationTime() const { return creationTime; }

};

int main(int argc, char const *argv[]){
  //String str("hello");
  //cout << str.get_creationTime() << endl;

  char* test = const_cast<char*>("hi");
  cout << sizeof(test) << endl;
  return 0;
}

