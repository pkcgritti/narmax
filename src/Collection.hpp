#ifndef _Collection_
#define _Collection_

#include <iostream>
#include <string>
#include <vector>

namespace narmax {
  class Collection {
  public:
    Collection(std::vector<double>&);
    Collection(std::vector<double>&, std::string);
    Collection(double&, int);
    // Collection(double &, int, string);
    // Collection(Collection&);
    // Collection(Collection&&);
    // vector<double> getData() { return _data; };
    // vector<double> getRange() { return _data; };

    friend std::ostream& operator<<(std::ostream&, const Collection&);
  private:
    std::vector<double> _data;
    std::string _name;
  };
};

#endif
