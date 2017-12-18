#include <algorithm>
#include "Collection.hpp"

namespace narmax {
  Collection::Collection(std::vector<double> &data) {
    _data = data;
    _name = "unamed";
  }

  Collection::Collection(std::vector<double> &data, std::string name) {
    _data = data;
    _name = name;
  }

  Collection::Collection(double &data, int len) {
    // TODO: Remember how to work with algorithm
    _data.resize(0);
    _name = "unamed";
    std::for_each(&data, &data + len,
                  [this] (double val) {
                    _data.push_back(val);
                  });
  }

  std::ostream& operator<<(std::ostream& os, const Collection& col) {
    os << "(" << col._name << ":" << col._data.size() << " samples)\n\t";
    if (col._data.size() == 0)
      return os << "Empty collection\n";

    if (col._data.size() > 12) {
      os << "[" << col._data[0];
      std::for_each(col._data.begin() + 1, col._data.begin() + 6,
                    [&os] (double datum) {
                      os << ", " << datum;
                    });
      os << ", ...";
      std::for_each(col._data.end() - 6, col._data.end(),
                    [&os] (double datum) {
                      os << ", " << datum;
                    });
      os << "]\n";
      return os;
    }

    os << "[" << col._data[0];
    std::for_each(col._data.begin() + 1, col._data.end(),
                  [&os] (double datum) {
                    os << ", " << datum;
                  });
    os << "]\n";
    return os;
  }

  // Collection::Collection(double &data, int len, string name) {
  // }
  // Collection(Collection&);
  // Collection(Collection&&);
};
