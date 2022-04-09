#include <string>  // default on leetcode
#include <vector>

using namespace std;  // default on leetcode

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    string prefix;
    size_t min_length = strs.front().length();
    for (const auto& s : strs) {
      min_length = min(s.length(), min_length);
    }
    for (size_t i = 0; i < min_length; ++i) {
      const char c = strs.front()[i];
      for (const auto& s : strs) {
        if (s[i] != c) return prefix;
      }
      prefix += c;
    }
    return prefix;
  }
};
