#include "gtest/gtest.h"

#include "src/algorithm/rotate-list.h"
#include "src/helpers/list-node.h"

#include <algorithm>
#include <vector>

using namespace leetcode;

TEST(RotateList, EmptyList) {
    ListNode *rotated_list = Solution().rotateRight(nullptr, 1337);
    EXPECT_EQ(rotated_list, nullptr);
}

TEST(RotateList, SimpleList) {
    ListNode *input = buildList({1, 2, 3, 4, 5});
    ListNode *expected_list = buildList({4, 5, 1, 2, 3});
    ListNode *rotated_list = Solution().rotateRight(input, 2);
    EXPECT_TRUE(compareList(rotated_list, expected_list));
}

TEST(RotateList, Symmetry) {
    ListNode *input = buildList({1, 2});
    ListNode *rotated_list = Solution().rotateRight(input, 2);
    EXPECT_TRUE(compareList(rotated_list, input));
}

TEST(RotateList, KBiggerThenList2Elements) {
    ListNode *input = buildList({1, 2});
    ListNode *expected_list = buildList({2, 1});
    ListNode *rotated_list = Solution().rotateRight(input, 3);
    EXPECT_TRUE(compareList(rotated_list, expected_list));
}

TEST(RotateList, KBiggerThenList3Elements) {
    ListNode *input = buildList({0, 1, 2});
    ListNode *expected_list = buildList({2, 0, 1});
    ListNode *rotated_list = Solution().rotateRight(input, 4);
    EXPECT_TRUE(compareList(rotated_list, expected_list));
}

TEST(RotateList, HugeK) {
    ListNode *input = buildList({1, 2, 3});
    ListNode *expected_list = buildList({2, 3, 1});
    ListNode *rotated_list = Solution().rotateRight(input, 2000000000);
    EXPECT_TRUE(compareList(rotated_list, expected_list));
}
