#include "MIMOFrame.hpp"
#include <algorithm>
#include <iomanip>

namespace narmax {
  namespace data {
    MIMOFrame::MIMOFrame() {}

    MIMOFrame::MIMOFrame(const std::string& fname) {
      // TODO: Read from filename
      std::cout << fname;
    }

    void MIMOFrame::push(const Collection& collection, bool isOut) {
      this->collections.push_back({
        collection,
        isOut
      });
    }

    std::ostream& operator<<(std::ostream& os, const MIMOFrame& frame) {
      std::size_t nameSpacing = frame.getNamePrintBoundaries();
      std::size_t numberSpacing = frame.getNumberPrintBoundaries();
      std::size_t numberLength = std::min((size_t) 8, frame.collections[0].collection.getSize());
      int precision = 6;

      os << "<MIMO Frame:" << frame.collections[0].collection.getSize() << " samples>\n";
      std::for_each(frame.collections.begin(), frame.collections.end(),
                    [&os, nameSpacing, numberSpacing, numberLength, precision] (const CollectionBuffer &cbuff) {
                      if (cbuff.isOutput) os << "OUT";
                      else os << " IN";
                      os << std::fixed << std::setw(nameSpacing + 2) << cbuff.collection.getName();
                      if (numberLength > 0) cbuff.collection.printSpaced(os, numberSpacing + precision + 4, 6, precision);
                      os << std::endl;
                    });
      os << std::endl;
      return os;
    }

    std::size_t MIMOFrame::getNamePrintBoundaries() const {
      std::vector<std::size_t> strLengths;
      std::for_each(collections.begin(), collections.end(),
                    [&strLengths] (const CollectionBuffer& cbuff) {
                      strLengths.push_back(cbuff.collection.getName().size());
                    });
      return *std::max_element(strLengths.begin(), strLengths.end());
    }

    std::size_t MIMOFrame::getNumberPrintBoundaries() const {
      std::vector<std::size_t> nDigits;
      std::for_each(collections.begin(), collections.end(),
                    [&nDigits] (const CollectionBuffer& cbuff) {
                      nDigits.push_back(cbuff.collection.largerDigit());
                    });
      return *std::max_element(nDigits.begin(), nDigits.end());
    }
  };
};
