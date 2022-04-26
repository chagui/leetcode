#include "src/algorithm/integer-to-roman.h"

#include <algorithm>
#include <vector>

#include "gtest/gtest.h"

using namespace leetcode;

TEST(IntegerToRoman, One) {
    EXPECT_EQ(Solution().intToRoman(1), "I");
}

TEST(IntegerToRoman, Three) {
    EXPECT_EQ(Solution().intToRoman(3), "III");
}

TEST(IntegerToRoman, Four) {
    EXPECT_EQ(Solution().intToRoman(4), "IV");
}

TEST(IntegerToRoman, FiftyEight) {
    EXPECT_EQ(Solution().intToRoman(58), "LVIII");
}

TEST(IntegerToRoman, ThousandNineHundredNinetyFour) {
    EXPECT_EQ(Solution().intToRoman(1994), "MCMXCIV");
}

TEST(IntegerToRoman, ThreeThousandNineHundredNinetyNine) {
    EXPECT_EQ(Solution().intToRoman(3999), "MMMCMXCIX");
}
