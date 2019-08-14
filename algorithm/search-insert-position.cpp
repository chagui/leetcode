// naive
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index{0};
        for (;(index < nums.size()) && (target > nums[index]); ++index) {}
        return index;
    }
};

// dichotomic search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg {0}, end {nums.size() - 1};

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
