#include <iostream>
#include <vector>
#include "Collection.hpp"
#include "gtest/gtest.h"

using namespace std;

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

  TEST(Collection, EmptyConstructor) {
    RecordProperty("description", "Empty constructors should work");
    narmax::Collection collection;
    std::cout << collection;
  }

  TEST(Collection, DoubleConstructor) {
    RecordProperty("description", "Double pointer constructor should work");
    double data[] = {1, 2, 3, 4};
    narmax::Collection collection(data, 4);
    for (int i = 0; i < 4; i++) {
      EXPECT_DOUBLE_EQ(data[i], collection[i]);
    }
  }

  TEST(Collection, VectorConstructor) {
    RecordProperty("description", "Vector constructor should work");
    std::vector<double> data = {1, 2, 3, 4};
    narmax::Collection collection(data);
    for (std::size_t i = 0; i < data.size(); i++) {
      EXPECT_DOUBLE_EQ(data[i], collection[i]);
    }
  }

  TEST(Collection, InitListConstructor) {
    RecordProperty("description", "Initialization list constructor should work");
    narmax::Collection collection({1.25, 4.25});
    EXPECT_DOUBLE_EQ(collection[0], 1.25);
    EXPECT_DOUBLE_EQ(collection[1], 4.25);
  }
}
