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

void dbgPure() {
  cout << "Checking how min & max returns\n";
  vector<string> strings;
  vector<size_t> lengths;

  strings.push_back("Hello world");
  strings.push_back("My name is mother fucker");
  strings.push_back("Another string");

  for_each(strings.begin(), strings.end(),
           [&lengths] (const string& str) {
             lengths.push_back(str.size());
           });

  cout <<  *std::max_element(lengths.begin(), lengths.end());

  printVector(strings);
  printVector(lengths);
}

void dbgCollection() {
  cout << "No debug for collection\n";
}

void dbfMIMOFrame() {
  narmax::data::MIMOFrame frame;
  narmax::data::Collection res({1, 2, 3, 4}, "Resistance");
  narmax::data::Collection var({5, 6, 7, 8}, "Variance");

  frame.push(res, true);
  frame.push(var);
  cout << frame;
}

// END

typedef void (*Callback)();
typedef struct {
  Callback fcn;
  string  name;
} CBList;

const CBList callbacks[] = {
  { dbgPure, "Debug pure" },
  { dbgCollection, "Debug collection" },
  { dbfMIMOFrame, "Debug mimo frame" }
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

