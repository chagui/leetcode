#include <numeric>

using namespace std; // default on leetcode
class Solution {
  public:
    int reverse(int x) {
        const int min = numeric_limits<int>::min() / 10;
        const int max = numeric_limits<int>::max() / 10;
        int reversedX = 0;
        while (x != 0) {
            if (reversedX < min || reversedX > max)
                return 0;
            reversedX *= 10;
            reversedX += x % 10;
            x /= 10;
        }
        return reversedX;
    }
};
