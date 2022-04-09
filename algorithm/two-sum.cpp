#include <unordered_map>
#include <vector>

// default on leetcode
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    // return twoSumBruteForce(nums, target);
    // return twoSumHashMapTwoPasses(nums, target);
    return twoSumHashMapOnePass(nums, target);
  }

  vector<int> twoSumBruteForce(vector<int>& nums, int target) {
    for (int valueIndex = 0; valueIndex < nums.size() - 1; ++valueIndex) {
      const int complement = target - nums[valueIndex];
      for (int complementIndex = valueIndex + 1; complementIndex < nums.size();
           ++complementIndex) {
        if (nums[complementIndex] == complement) {
          return {valueIndex, complementIndex};
        }
      }
    }
    throw runtime_error("No solution");
  }

  vector<int> twoSumHashMapTwoPasses(vector<int>& nums, int target) {
    // build value to indexes (the input may contains multiple times the same
    // value) look-up
    unordered_map<int, int> valueToIndex{{nums[0], 0}};
    for (int index = 0; index < nums.size(); ++index) {
      valueToIndex.insert_or_assign(nums[index], index);
    }

    for (int index = 1; index < nums.size() - 1; ++index) {
      const int complement = target - nums[index];
      auto it = valueToIndex.find(complement);
      if (it != valueToIndex.end() && it->second != index) {
        return {index, it->second};
      }
    }
    throw runtime_error("No solution");
  }

  vector<int> twoSumHashMapOnePass(vector<int>& nums, int target) {
    unordered_map<int, int> valueToIndex{{nums[0], 0}};

    for (int index = 1; index < nums.size(); ++index) {
      const int value = nums[index];
      const int complement = target - value;
      const auto complementIt = valueToIndex.find(complement);
      if (complementIt != valueToIndex.end() && complementIt->second != index) {
        return {complementIt->second, index};
      }
      valueToIndex[value] = index;
    }
    throw runtime_error("No solution");
  }
};
