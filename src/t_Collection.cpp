#include <iostream>
#include <vector>
#include "Collection.hpp"
#include "gtest/gtest.h"

namespace {
  class CollectionTest : public ::testing::Test {
  protected:
    // You can remove any or all of the following
    // functions if the body is empty

    CollectionTest() {
      // Setup work for each test in here
    }

    virtual ~CollectionTest() {
      // Clean-up work in here
    }

    virtual void SetUp() {
      // Code here will be called immediately
      // after the constructor (right before each
      // test).
    }

    virtual void TearDown() {
      // Code here will be called immediately
      // aftereach test (right before the
      // destructor)
    }
  };

  TEST_F(CollectionTest, creationTest) {
    std::vector<double> vec;
    vec.push_back(1.0);
    vec.push_back(2.0);
    narmax::Collection c(vec);
    EXPECT_EQ(vec[1], 2.0);
    // Exercises the Xyz feature of Foo.
  }
}
