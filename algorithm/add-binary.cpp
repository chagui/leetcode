class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty()) return b;
        if (b.empty()) return a;

        std::string result;
        result.reserve(std::max(a.length(), b.length()) + 1);
        auto da = a.crbegin();
        auto db = b.crbegin();
        unsigned short digit = 0;
        while (da != a.crend() || db != b.crend() || digit != 0) {
            if (da != a.crend()) {
                digit += *da - '0';
                ++da;
            }
            if (db != b.crend()) {
                digit += *db - '0';
                ++db;
            }
            result.push_back((digit == 1 || digit == 3) ? '1' : '0');
            digit = digit / 2;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
