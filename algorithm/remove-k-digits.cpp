namespace {
    bool isZero(char c) {
        return c == '0';
    }
}

class Solution {
public:
    // too slow
    string removeKdigitsRec(string num, int k) {
        if (k >= num.length() || num.empty()) return "";
        if (k == 0 || num.length() == 1) return num;
        if (num.length() == 2) return (num.front() < num.back()) ? string(1, num.front()) : string(1, num.back());
        // best case scenario
        if (num[1] == '0') {
            auto first_non_zero = find_if_not(++num.begin(), num.end(), isZero);
            if (first_non_zero == num.end()) return "";
            return removeKdigitsRec(num.substr(distance(num.begin(), first_non_zero)), k - 1);
        }
        string s = num.substr(1);
        string with_front = removeKdigitsRec(s, k);
        string without_front = removeKdigitsRec(s, k - 1);
        // check if we removed more than one digit 
        size_t length_diff = (with_front.length() + 1) - without_front.length();
        if (length_diff == 0) return (without_front.front() < num.front()) ? without_front : num.front() + with_front;
        return (with_front.length() > without_front.length()) ? with_front : without_front;
    }

    string removeKdigits(string num, int k) {
        if (num.length() <= k) return "0";
        string result;
        result.reserve(num.length() - k);
        auto it = num.begin();
        while (it != num.end() && k != 0) {
            if (*it == '0' && result.size() <= k) {
                k -= result.size();
                result.clear();
                it = find_if_not(it, num.end(), isZero);
                continue;
            }
            if (!result.empty() && *it < result.back()) {
                result.pop_back();
                --k;
            } else {
                result.push_back(*it);
                ++it;
            }
        }
        if (it != num.end()) copy(it, num.end(), back_inserter(result));
        else if (k > result.length()) return "0";
        else if (k > 0) result.resize(result.length() - k);
        return (result.empty()) ? "0" : result;
    }
};

