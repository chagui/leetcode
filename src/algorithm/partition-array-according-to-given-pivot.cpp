#include "src/algorithm/partition-array-according-to-given-pivot.h"

std::vector<int> leetcode::Solution::pivotArray(vector<int> &nums, int pivot) {
    vector<int> pivoted(nums.size(), pivot);
    int index = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < pivot) {
            pivoted[index++] = nums[i];
        }
    }

    index = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
        if (nums[i] > pivot) {
            pivoted[index--] = nums[i];
        }
    }

    return pivoted;
}
