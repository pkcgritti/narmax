#ifndef _MIMOFrame_
#define _MIMOFrame_

#include <vector>
#include <string>
#include "Collection.hpp"

namespace narmax {
  namespace data {
    struct CollectionBuffer {
      Collection collection;
      bool         isOutput;
    };
    /**
     * Multiple input multiple output frame (MIMOFrame)
     * is used to manipulate the working dataset.
     */
    class MIMOFrame {
      public:
        MIMOFrame();
        MIMOFrame(const std::string&);
        void push(const Collection&, bool isOut = false);
        
        friend std::ostream& operator<<(std::ostream&, const MIMOFrame&);
      private:
        std::size_t getNamePrintBoundaries() const;
        std::size_t getNumberPrintBoundaries() const;
        std::vector<CollectionBuffer> collections;
    };
  };
}

#endif
