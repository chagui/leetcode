#include "src/algorithm/zigzag-conversion.h"

#include <iostream>
#include <vector>

namespace {
    std::string laydownZigzagMatrix(std::string s, int numRows) {
        std::vector<std::string> parts(numRows);

        for (int index = 0; index < s.length();) {
            // go down vertically
            for (int row = 0; index < s.length() && row < numRows; ++row, ++index) {
                parts[row] += s[index];
            }

            // go up in diagonal
            for (int row = numRows - 2; index < s.length() && row > 0; --row, ++index) {
                parts[row] += s[index];
            }
        }

        std::string zigzag;
        zigzag.reserve(s.length());
        for (const std::string &part : parts) {
            zigzag += part;
        }
        return zigzag;
    }

    std::string lookAheadCopy(std::string s, int numRows) {
        std::string zigzag;
        const int step = numRows * 2 - 2;

        for (int index = 0; index < s.length(); index += step) {
            zigzag += s[index];
        }

        for (int row = 1; row < numRows - 1; ++row) {
            const int offset = (numRows - row) * 2 - 2;

            for (int index = row; index < s.length(); index += step) {
                zigzag += s[index];
                if (index + offset < s.length()) {
                    zigzag += s[index + offset];
                }
            }
        }

        for (int index = numRows - 1; index < s.length(); index += step) {
            zigzag += s[index];
        }

        return zigzag;
    }
}  // namespace

std::string leetcode::Solution::convert(std::string s, int numRows) {
    if (numRows == 1 || s.length() < numRows) {
        return s;
    }
    // return laydownZigzagMatrix(s, numRows);
    return lookAheadCopy(s, numRows);
}
