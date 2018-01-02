#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Collection.hpp"
#include "MIMOFrame.hpp"

using namespace std;
using namespace narmax;

typedef vector<double> dvec;

void printVector(const vector<string>& vec);
template <typename T>
void printVector(const vector<T>& vec);

// Place your code below

void debug() {
  narmax::data::Collection c1({1, 223, -3123.1231241239012931, 4, 5, 6, 7}, "Thermal Resistance");
  narmax::data::Collection c2({1, 2, 3, 4, 5, 6, 7}, "Volume");
  narmax::data::MIMOFrame frame;
  frame.push(c1);
  frame.push(c2);

  cout << frame;
}

// END

typedef void (*Callback)();
typedef struct {
  Callback fcn;
  string  name;
} CBList;

const CBList callbacks[] = {
  { debug, "Debug function" },
};

const unsigned int CBListLen = sizeof(callbacks) / sizeof(CBList);

int main() {
  for (unsigned int i = 0; i < CBListLen; i++) {
    const CBList &elem = callbacks[i];
    cout << "Calling " << elem.name << endl;
    elem.fcn();
    cout << endl;
  }
  return 0;
}

void printVector(const vector<string>& vec) {
  if (!vec.size()) return;
  cout << "[";
  for_each(vec.begin(), vec.end()-1,
           [] (const string &val) {
             cout << "\"" << val << "\", ";
           });
  cout << "\"" << vec[vec.size()-1] << "\"]\n";
}

template <typename T>
void printVector(const vector<T>& vec) {
  if (!vec.size()) return;
  cout << "[";
  for_each(vec.begin(), vec.end()-1,
           [] (const T &val) {
             cout << val << ", ";
           });
  cout << vec[vec.size()-1] << "]\n";
}

