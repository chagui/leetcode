#include "gtest/gtest.h"

#include "src/algorithm/spiral-matrix.h"

using namespace leetcode;

TEST(SpiralMatrix, ThreeByThree) {
    std::vector<std::vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    const std::vector<int> expected_elements{1, 2, 3, 6, 9, 8, 7, 4, 5};
    const auto elements = Solution().spiralOrder(matrix);
    EXPECT_EQ(elements, expected_elements);
}

TEST(SpiralMatrix, ThreeByFour) {
    std::vector<std::vector<int>> matrix{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };
    const std::vector<int> expected_elements{1,  2,  3, 4, 8, 12,
                                             11, 10, 9, 5, 6, 7};
    const auto elements = Solution().spiralOrder(matrix);
    EXPECT_EQ(elements, expected_elements);
}

TEST(SpiralMatrix, OneByOne) {
    std::vector<std::vector<int>> matrix{{1}};
    const std::vector<int> expected_elements{1};
    const auto elements = Solution().spiralOrder(matrix);
    EXPECT_EQ(elements, expected_elements);
}

TEST(SpiralMatrix, TwoByOne) {
    std::vector<std::vector<int>> matrix{{3}, {2}};
    const std::vector<int> expected_elements{3, 2};
    const auto elements = Solution().spiralOrder(matrix);
    EXPECT_EQ(elements, expected_elements);
}

TEST(SpiralMatrix, ThreeByOne) {
    std::vector<std::vector<int>> matrix{{1}, {2}, {3}};
    const std::vector<int> expected_elements{1, 2, 3};
    const auto elements = Solution().spiralOrder(matrix);
    EXPECT_EQ(elements, expected_elements);
}

TEST(SpiralMatrix, OneByThree) {
    std::vector<std::vector<int>> matrix{{1, 2, 3}};
    const std::vector<int> expected_elements{1, 2, 3};
    const auto elements = Solution().spiralOrder(matrix);
    EXPECT_EQ(elements, expected_elements);
}

TEST(SpiralMatrix, FourByFour) {
    std::vector<std::vector<int>> matrix{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
    };
    const std::vector<int> expected_elements{1,  2,  3, 4, 8, 12, 16, 15,
                                             14, 13, 9, 5, 6, 7,  11, 10};
    const auto elements = Solution().spiralOrder(matrix);
    EXPECT_EQ(elements, expected_elements);
}
