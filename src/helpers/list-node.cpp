#include "src/helpers/list-node.h"

#include <iostream>

leetcode::ListNode *leetcode::buildList(const std::vector<int> &values) {
    ListNode *node = nullptr;
    for (auto val = values.rbegin(); val != values.rend(); ++val) {
        node = new ListNode(*val, node);
    }
    return node;
}

bool leetcode::compareList(leetcode::ListNode *l1, leetcode::ListNode *l2) {
    for (; l1 != nullptr && l2 != nullptr && l1->val == l2->val; l1 = l1->next, l2 = l2->next) {
    }
    return l1 == nullptr && l2 == nullptr;
}

void leetcode::printList(leetcode::ListNode *head, char sep /* = ' '*/, char eol /* = '\0'*/) {
    for (; head != nullptr; head = head->next) {
        std::cout << head->val << sep;
    }
    if (eol != '\0') {
        std::cout << eol;
    }
}
