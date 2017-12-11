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
    _name = "unamed";
  }

  // Collection::Collection(double &data, int len, string name) {
  // }
  // Collection(Collection&);
  // Collection(Collection&&);
};
