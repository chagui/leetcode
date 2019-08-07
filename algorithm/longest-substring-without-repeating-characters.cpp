class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) return s.size();
        std::unordered_map<char, std::size_t> seen;
        std:size_t longest {0}, idx {0}, start {0};
        
        for (; idx < s.size(); ++idx) {
            char c = s[idx];
            if (seen.find(c) != seen.end() && seen[c] >= start) {
                longest = std::max(longest, idx - start);
                start = seen[c] + 1;
            }
            seen[c] = idx;
        }
        return std::max(longest, idx - start);
    }
};
