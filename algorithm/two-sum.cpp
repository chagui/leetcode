class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        vector<int>::size_type left = 0, right = nums.size() - 1;
        int current = sorted_nums[left] + sorted_nums[right];
        while (current != target) {
            if (current > target) --right;
            else ++left;
            current = sorted_nums[left] + sorted_nums[right];
        }
        const auto left_pos = find(nums.begin(), nums.end(), sorted_nums[left]);
        const auto right_pos = find(nums.rbegin(), nums.rend(), sorted_nums[right]);
        return {std::distance(nums.begin(), left_pos), std::distance(nums.begin(), right_pos.base()) - 1};
    }
};
