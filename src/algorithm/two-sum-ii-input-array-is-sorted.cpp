#include <vector>

using namespace std; // default on leetcode

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int low = 0, high = numbers.size() - 1;
    while (low < high) {
      const int value = numbers[low] + numbers[high];
      if (value == target) {
        return {low + 1, high + 1};
      } else if (value > target) {
        --high;
      } else {
        ++low;
      }
    }
    throw runtime_error("no solution");
  }
};
