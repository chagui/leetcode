#include "src/algorithm/partition-array-according-to-given-pivot.h"

#include <vector>

#include "gtest/gtest.h"

using namespace leetcode;

TEST(PartitionArrayAccordingToGivenPivot, EmptyList) {
    std::vector<int> input {};
    const std::vector<int> result = Solution().pivotArray(input, 10);
    std::vector<int> expected {};
    EXPECT_EQ(expected, result);
}

TEST(PartitionArrayAccordingToGivenPivot, SimpleArray) {
    std::vector<int> input {9, 12, 5, 10, 14, 3, 10};
    const std::vector<int> result = Solution().pivotArray(input, 10);
    std::vector<int> expected {9, 5, 3, 10, 10, 12, 14};
    EXPECT_EQ(expected, result);
}
