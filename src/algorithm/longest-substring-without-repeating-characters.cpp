#include <string> // default on leetcode
#include <unordered_map>

using namespace std; // default on leetcode

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() < 2)
      return s.size();
    unordered_map<char, size_t> seen;
    size_t longest{0}, idx{0}, start{0};

    for (; idx < s.size(); ++idx) {
      char c = s[idx];
      if (seen.find(c) != seen.end() && seen[c] >= start) {
        longest = max(longest, idx - start);
        start = seen[c] + 1;
      }
      seen[c] = idx;
    }
    return max(longest, idx - start);
  }
};
