#include "gtest/gtest.h"
#include <vector>


class VectorFixture : public ::testing::Test {
protected:
    void SetUp() override {

    }

    void TearDown() override {

    }
    std::vector<int> container_;
};

TEST_F(VectorFixture, TestCapacity) {
    EXPECT_EQ(container_.capacity(), 10);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}