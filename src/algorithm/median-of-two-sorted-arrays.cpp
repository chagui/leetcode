#include <vector>

using namespace std;  // default on leetcode

class Solution {
   public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        auto it1 = nums1.begin(), it2 = nums2.begin();
        size_t number_of_elements = nums1.size() + nums2.size(), pos = 0;
        if (number_of_elements % 2 == 1) {
            size_t median_pos = number_of_elements / 2;
            while (it1 != nums1.end() && it2 != nums2.end()) {
                if (*it1 < *it2) {
                    if (pos == median_pos) return *it1;
                    ++pos;
                    ++it1;
                } else {
                    if (pos == median_pos) return *it2;
                    ++pos;
                    ++it2;
                }
            }
            while (it1 != nums1.end()) {
                if (pos == median_pos) return *it1;
                ++pos;
                ++it1;
            }
            while (pos != median_pos) {
                if (pos == median_pos) return *it2;
                ++pos;
                ++it2;
            }
            return *it2;
        }
        size_t median_high_pos = number_of_elements / 2;
        size_t median_low_pos = median_high_pos - 1;
        double median_low;
        while (it1 != nums1.end() && it2 != nums2.end()) {
            if (*it1 < *it2) {
                if (pos == median_low_pos) {
                    median_low = *it1;
                } else if (pos == median_high_pos)
                    return (median_low + *it1) / 2;
                ++pos;
                ++it1;
            } else {
                if (pos == median_low_pos) {
                    median_low = *it2;
                } else if (pos == median_high_pos)
                    return (median_low + *it2) / 2;
                ++pos;
                ++it2;
            }
        }
        while (it1 != nums1.end()) {
            if (pos == median_low_pos) {
                median_low = *it1;
            } else if (pos == median_high_pos)
                return (median_low + *it1) / 2;
            ++pos;
            ++it1;
        }
        while (pos != median_high_pos) {
            if (pos == median_low_pos) {
                median_low = *it2;
            }
            ++pos;
            ++it2;
        }
        return (median_low + *it2) / 2;
    }
};
