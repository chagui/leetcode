#include <numeric>
#include <string>  // default on leetcode
#include <unordered_map>
#include <vector>

using namespace std;  // default on leetcode

class Solution {
    const unordered_map<char, const string> lookup {
        {'2',  "abc"},
        {'3',  "def"},
        {'4',  "ghi"},
        {'5',  "jkl"},
        {'6',  "mno"},
        {'7', "pqrs"},
        {'8',  "tuv"},
        {'9', "wxyz"},
    };

   public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        const auto count_permutations = [this](int accu, const char d) { return accu * lookup.at(d).length(); };
        auto nb_of_permutations = accumulate(digits.begin(), digits.end(), 1, count_permutations);

        vector<string> permutations;
        permutations.reserve(nb_of_permutations);
        add_permutations("", 0, digits, permutations);
        return permutations;
    }

    void add_permutations(string prefix, int pos, const string &digits, vector<string> &permutations) {
        if (pos == digits.length()) {
            permutations.push_back(prefix);
            return;
        }
        for (const char c : lookup.at(digits[pos])) {
            add_permutations(prefix + c, pos + 1, digits, permutations);
        }
    }
};
