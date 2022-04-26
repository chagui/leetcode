#include "src/algorithm/partition-list.h"

#include <algorithm>
#include <vector>

#include "gtest/gtest.h"
#include "src/helpers/list-node.h"

using namespace leetcode;

TEST(PartitionList, EmptyList) {
    ListNode *rotated_list = Solution().partition(nullptr, 42);
    EXPECT_EQ(rotated_list, nullptr);
}

TEST(PartitionList, SimpleList) {
    ListNode *input = buildList({1, 4, 3, 2, 5, 2});
    ListNode *expected_list = buildList({1, 2, 2, 4, 3, 5});
    ListNode *rotated_list = Solution().partition(input, 3);
    EXPECT_TRUE(compareList(rotated_list, expected_list));
}
