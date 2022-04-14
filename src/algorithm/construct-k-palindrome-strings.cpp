#include <algorithm>
#include <bitset>
#include <string> // default on leetcode
#include <unordered_map>

using namespace std; // default on leetcode

class Solution {
public:
  bool canConstruct(string s, int k) { return optimizedForEnglish(s, k); }

  // optimize solution in both space and time by assuming input will only be
  // lower case english letters
  bool optimizedForEnglish(string s, int k) {
    if (s.empty() || s.length() == k)
      return true;
    if (s.length() < k)
      return false;
    // assumes input is always lower case english letter
    std::bitset<26> count_is_odd;
    for (char c : s) {
      count_is_odd.flip(c - 'a');
    }
    return count_is_odd.count() <= k;
  }

  bool naive(string s, int k) {
    if (s.empty() || s.length() == k)
      return true;
    if (s.length() < k)
      return false;
    std::unordered_map<char, std::size_t> count;
    for (char c : s) {
      ++count[c];
    }
    int num_of_odd =
        std::count_if(count.begin(), count.end(),
                      [](const auto &i) { return i.second % 2 != 0; });
    return num_of_odd <= k;
  }
};
