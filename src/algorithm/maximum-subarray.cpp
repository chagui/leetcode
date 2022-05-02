#include <iostream>
#include <limits>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums.front();
        }
        int sum = 0, maxSum = -10000;  // invariant: -10^4 <= nums[i] <= 10^4
        for (int num : nums) {
            sum = max(sum + num, num);
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};

TEST(MaximumSubarray, OneElement) {
    vector<int> array {42};
    const int result = Solution().maxSubArray(array);
    EXPECT_EQ(result, 42);
}

TEST(MaximumSubarray, Example1) {
    vector<int> array {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    const int result = Solution().maxSubArray(array);
    EXPECT_EQ(result, 6);
}

TEST(MaximumSubarray, Example2) {
    vector<int> array {5, 4, -1, 7, 8};
    const int result = Solution().maxSubArray(array);
    EXPECT_EQ(result, 23);
}

TEST(MaximumSubarray, Example3) {
    vector<int> array {-2, 1};
    const int result = Solution().maxSubArray(array);
    EXPECT_EQ(result, 1);
}

TEST(MaximumSubarray, OnlyNegatives) {
    vector<int> array {-2, -1, -3};
    const int result = Solution().maxSubArray(array);
    EXPECT_EQ(result, -1);
}
