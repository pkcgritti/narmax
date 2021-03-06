#include <algorithm>
#include <iomanip>
#include "Collection.hpp"

namespace narmax {
  namespace data {
    Collection::Collection() {
      this->name = "unamed";
    }

    Collection::Collection(double* data, int len) {
      this->data.resize(0);
      this->name = "unamed";
      std::for_each(data, data + len,
          [this] (const double& val) {
          this->data.push_back(val);
          });
    }

    Collection::Collection(double* data, int len, const std::string& name) {
      this->data.resize(0);
      this->name = name; 
      std::for_each(data, data + len,
          [this] (const double& val) {
          this->data.push_back(val);
          });
    }

    Collection::Collection(const std::vector<double>& data) : data(data), name("unamed") {}
    Collection::Collection(const std::vector<double>& data, const std::string& name) : data(data), name(name) {}

    Collection::Collection(std::initializer_list<double> il) {
      this->data.resize(0);
      this->name = "unamed";
      std::for_each(il.begin(), il.end(),
          [this] (const double& val) {
          this->data.push_back(val);
          });
    }

    Collection::Collection(std::initializer_list<double> il, const std::string& name) {
      this->data.resize(0);
      this->name = name;
      std::for_each(il.begin(), il.end(),
          [this] (const double& val) {
          this->data.push_back(val);
          });
    }

    Collection::Collection(const Collection& other) {
      if (this != &other) {
        this->name = other.name;
        this->data = other.data;
      }
    }

    Collection::Collection(Collection&& other) {
      if (this != &other) {
        this->name = std::move(other.name);
        this->data = std::move(other.data);
        other.name = "unamed";
      }
    }

    std::pair<double, std::size_t> Collection::max() const {
      auto it = std::max_element(data.begin(), data.end());
      std::pair<double, std::size_t> res(*it, it - data.begin());
      return res;
    }

    std::pair<double, std::size_t> Collection::min() const {
      auto it = std::min_element(data.begin(), data.end());
      std::pair<double, std::size_t> res(*it, it - data.begin());
      return res;
    }

    std::size_t Collection::largerDigit() const {
      size_t digits = 0;
      int max = (int) this->max().first, 
          min = (int) this->min().first;

      int probe = std::max(std::abs(max), std::abs(min));
      while(probe > 0) {
        probe /= 10;
        digits++;
      }
      return digits;
    }

    std::ostream& operator<<(std::ostream& os, const Collection& col) {
      os << "(" << col.name << ":" << col.data.size() << " samples)\n\t";
      if (col.data.size() == 0)
        return os << "Empty collection\n";

      if (col.data.size() > 12) {
        os << "[" << col.data[0];
        std::for_each(col.data.begin() + 1, col.data.begin() + 6,
            [&os] (double datum) {
            os << ", " << datum;
            });
        os << ", ...";
        std::for_each(col.data.end() - 6, col.data.end(),
            [&os] (double datum) {
            os << ", " << datum;
            });
        os << "]\n";
        return os;
      }

      os << "[" << col.data[0];
      std::for_each(col.data.begin() + 1, col.data.end(),
          [&os] (double datum) {
          os << ", " << datum;
          });
      os << "]\n";
      return os;
    }

    std::ostream& Collection::printSpaced(std::ostream& os, std::size_t spacing, std::size_t limit, int precision) const {
      std::size_t max = std::min(limit, data.size());
      std::for_each(data.begin(), data.begin() + max,
                    [&os, spacing, precision] (const double& val) {
                      os << std::fixed << std::setprecision(precision) << std::setw(spacing) << val;
                    });
      return os;
    }
  };
};
