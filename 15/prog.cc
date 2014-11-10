#include <iostream>
#include <iomanip>
using namespace std;

#define SIZE 10 //100
#define NAME_WIDTH 20

static unsigned int n = 0;

class Student {
public:
  string name;
  unsigned int num;
  string depart;
  string num_speciality;
  string birthday;
  string address;
  string phone;

  Student(string na = "Default Name", 
          unsigned int nu = ++n, 
          string dep = "Department", 
          string nu_s = "230105/c", 
          string bi = "01/02/2003", 
          string ad = "Moscow", 
          string ph = "+7 (123) 456-78-90") {
    name = na;
    num = nu;
    depart = dep;
    num_speciality = nu_s;
    birthday = bi;
    address = ad;
    phone = ph;
  }
  
};

bool operator< (Student &stu1, Student &stu2) {
  return (stu1.name < stu2.name);
}

bool operator> (Student &stu1, Student &stu2) {
  return (stu1.name > stu2.name);
}

ostream& operator<< (ostream &out, const Student &stu) {
    out << setiosflags(ios::left);
    out << " " << setw(NAME_WIDTH) << stu.name 
        << " " << stu.num
        << " " << stu.depart
        << " " << stu.num_speciality
        << " " << stu.birthday
        << " " << stu.address
        << " " << stu.phone;
    return out;
}

template <typename T>
void output(T* array) {
  for(int i=0; i<SIZE; i++) 
    cout << array[i] << endl;
}

/*
  Name: qsort (quick sort) or Hoare sort
  Cases: 
      O(n*log(n))   --best
      O(n*log(n))   --average
      O(n^2)        --worst
*/
template <typename T>
void sort(T* array, int l=0, int r=SIZE-1) {
  int i=l;
  int j=r;

  // Выбираем опорный элемент
  T* pivot = &array[static_cast<int>((i+j)/2)]; 

  // Сортируем относительно опроного элемента
  do {
    while (array[i] < *pivot)
      i++;
    while (array[j] > *pivot)
      j--;
    if (i<=j) {
      T temp = array[i];
      array[i] = array[j];
      array[j] = temp;
      i++;
      j--;
    }
  } while (i<j);
  
  // Обрабатываем полученные две части
  if (l<j)
    sort(array, l, j);
  if (i<r)
    sort(array, i, r);
}

int main() {
  Student* array = new Student[SIZE];
  array[0].name = "Danilov Alex";
  array[1].name = "Tokmakova Viktorya";
  array[2].name = "Bogdanova V";
  array[3].name = "Popov D";
  array[4].name = "Pron'kin O";
  array[5].name = "Efim";
  array[6].name = "Tylor";
  array[7].name = "Brian";
  array[8].name = "Linus Torvalds";
  array[9].name = "Cat";

  cout << "Unsorted:" << endl;
  output(array);
  cout << endl;

  cout << "Sorted:" << endl;
  sort(array);
  output(array);

  cout << endl;
  delete[] array;

  return 0;
}
