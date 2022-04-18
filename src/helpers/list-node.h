#ifndef LEETCODE_HELPERS_LIST_NODE_H_
#define LEETCODE_HELPERS_LIST_NODE_H_

#include <vector>

namespace leetcode {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *buildList(const std::vector<int> &);
    bool compareList(ListNode *, ListNode *);
    void printList(ListNode *head, char sep = ' ', char eol = '\n');
} // namespace leetcode

#endif // LEETCODE_HELPERS_LIST_NODE_H_
