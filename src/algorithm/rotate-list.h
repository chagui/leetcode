#ifndef LEETCODE_ALGORITHM_ROTATE_LIST_H_
#define LEETCODE_ALGORITHM_ROTATE_LIST_H_

namespace leetcode {
    struct ListNode;

    class Solution {
       public:
        ListNode *rotateRight(ListNode *head, int k);
    };
}  // namespace leetcode

#endif  // LEETCODE_ALGORITHM_ROTATE_LIST_H_
