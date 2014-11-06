#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

const int mon_len[] = {31,28,31,30,31,30,31,31,30,31,30,31};

struct Date {
private:
  unsigned short year;
  unsigned char month, day;
public:

  Date(unsigned short y = 2000, unsigned char m = 1, unsigned char d = 1) {
    year = y;
    month = m;
    day = d;
  }

  int get_year() const { return year; } 
  int get_month() const { return month; } 
  int get_day() const { return day; } 

  void set_year(unsigned short y) {
    if (y > 0 ) {
      year = y;
    } else {
      throw range_error("Error: Value of year is wrong. It must be > 0"); 
    }
  }

  void set_month(unsigned char m) {
    if (m >= 1 && m <= 12) {
      month = m;
    } else {
      throw range_error("Error: Value of month is wrong. It must be between 1 and 12 included"); 
    }
  }

  void set_day(unsigned char d) {
    if (d >= 1 && d <= mon_len[get_month()-1]) {
      day = d;
    } else {
      throw range_error("Error: Value of day is wrong. It must be between 1 and count days of the month included"); 
    }
  }

  Date &operator++() { // for prefix // Date &operator++(int) { --for postfix
    ++day;
    if (day > mon_len[get_month() - 1]) {
      day = 1;
      ++month;
      if (month > 12) {
        month = 1;
        ++year;
      }
    }
    return *this;
  }

  Date &operator--() { // for prefix // Date &operator--(int) { --for postfix
    --day;
    if ( day == 0 ) { 
      --month;
      if (month == 0) {
        month = 12;
        --year;
      }
      day = mon_len[month - 1];
    }
    return *this;
  }
};

ostream &operator << (ostream &out, const Date &date) {
  out << 
    date.get_year() << "." << 
    int(date.get_month()) << "." << 
    int(date.get_day());
  return out;
}

void input_date(Date &date) {
  int val;
  while (true) {
    cout << "\nInput a new date:" << endl;
    try {
      cout << "Input year: ( > 0 ): ";
      cin >> val;
      date.set_year(val);
      cout << "Input month: (from 1 till 12): ";
      cin >> val;
      date.set_month(val);
      cout << "Input day: (from 1 till the count of days in the month): ";
      cin >> val;
      date.set_day(val);
      break;
    } catch (range_error& e ) {
      cout << e.what() << endl;
    }
    cout << "\nTry again." << endl;
  }
}

int main() {
  Date date;

  cout << "List of commands:" << endl;
  cout << "\t output" << endl;
  cout << "\t input" << endl;
  cout << "\t inc" << endl;
  cout << "\t decr" << endl;
  cout << "\t quite" << endl;
  cout << endl;

  bool quite = false;
  string cmd = "";
  while (! quite) {
    cout << "Input command: ";
    cin >> cmd;

    if (cmd == "output") {
      cout << date << endl;
    } else if ( cmd == "input") {
      input_date(date);
    } else if ( cmd == "inc") {
      ++date;
    } else if ( cmd == "decr") {
      --date;
    } else if ( cmd == "quite") {
      quite = true;
      cout << "exit" << endl;
    } else {
      cout << "Unknown command!" << endl;
    }
  }

  return 0;
}

