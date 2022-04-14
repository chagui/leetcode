#include <vector>

using namespace std; // default on leetcode

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    // return naive(nums, target);
    return binarySearch(nums, target);
  }

  int naive(vector<int> &nums, int target) {
    int index{0};
    for (; (index < nums.size()) && (target > nums[index]); ++index) {
    }
    return index;
  }

  int binarySearch(vector<int> &nums, int target) {
    size_t beg{0}, end{nums.size() - 1};

    while (beg <= end) {
      int mid = beg + (end - beg) / 2;
      if (target > nums[mid]) {
        beg = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return beg;
  }
};
