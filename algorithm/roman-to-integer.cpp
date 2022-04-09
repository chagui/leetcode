#include <string>  // default on leetcode
#include <unordered_map>

using namespace std;  // default on leetcode

namespace {
unordered_map<char, int> symbolToValue{
    {'O', 0},  {'I', 1},   {'V', 5},   {'X', 10},
    {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000},
};
}

class Solution {
 public:
  int romanToInt(string s) {
    if (s.empty()) return 0;
    s.push_back('0');  // sentinel

    int number = 0;
    for (size_t index = 0; index < s.size() - 1; ++index) {
      const char c{s[index]}, nextc{s[index + 1]};
      // detect it a substraction
      if (symbolToValue[c] < symbolToValue[nextc] &&
          (c == 'I' || c == 'X' || c == 'C')) {
        number -= symbolToValue[c];
      } else {
        number += symbolToValue[c];
      }
    }
    return number;
  }
};
