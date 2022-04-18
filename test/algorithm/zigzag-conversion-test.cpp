#include "gtest/gtest.h"

#include "src/algorithm/zigzag-conversion.h"

using namespace leetcode;

TEST(ZigzagConversion, EmptyString) {
    const auto result = Solution().convert("", 3);
    EXPECT_EQ(result, "");
}

TEST(ZigzagConversion, OneRow) {
    const auto result = Solution().convert("A", 1);
    EXPECT_EQ(result, "A");
}

TEST(ZigzagConversion, ThreeRows) {
    const auto result = Solution().convert("PAYPALISHIRING", 3);
    EXPECT_EQ(result, "PAHNAPLSIIGYIR");
}

TEST(ZigzagConversion, FourRows) {
    const auto result = Solution().convert("PAYPALISHIRING", 4);
    EXPECT_EQ(result, "PINALSIGYAHRPI");
}

TEST(ZigzagConversion, FiveRows) {
    const auto result = Solution().convert("PAYPALISHIRING", 5);
    EXPECT_EQ(result, "PHASIYIRPLIGAN");
}
