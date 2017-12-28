#ifndef _Collection_
#define _Collection_

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

namespace narmax {
  namespace data {
    class Collection {
      public:
        Collection();
        Collection(double*, int);
        Collection(double*, int, const std::string&);
        Collection(const std::vector<double>&);
        Collection(const std::vector<double>&, const std::string&);
        Collection(std::initializer_list<double>);
        Collection(std::initializer_list<double>, const std::string&);
        Collection(const Collection&);
        Collection(Collection &&);

        std::vector<double>& getData() { return data; };
        std::string getName() const { return name; };
        void setName(std::string name) { this->name = name; };
        std::size_t getSize() const { return data.size(); };

        double& operator[](int index) { return data[index]; };
        double at(int index) { return data[index]; };

        friend std::ostream& operator<<(std::ostream&, const Collection&);
        std::ostream& printSpaced(std::ostream&, std::size_t, std::size_t limit = 4) const;
      private:
        std::vector<double> data;
        std::string name;
    };
  };
};

#endif
