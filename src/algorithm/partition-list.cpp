#include "src/algorithm/partition-list.h"

#include "src/helpers/list-node.h"

leetcode::ListNode *leetcode::Solution::partition(ListNode *head, int x) {
    ListNode left_sentinel;
    ListNode *left_tail = &left_sentinel;
    ListNode right_sentinel;
    ListNode *right_tail = &right_sentinel;

    for (; head != nullptr; head = head->next) {
        if (head->val < x) {
            left_tail->next = new ListNode(head->val);
            left_tail = left_tail->next;
        } else {
            right_tail->next = new ListNode(head->val);
            right_tail = right_tail->next;
        }
    }

    left_tail->next = right_sentinel.next;
    right_tail->next = nullptr;
    return left_sentinel.next;
}
