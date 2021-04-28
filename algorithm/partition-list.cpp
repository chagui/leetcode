/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode new_head; // sentinel
        ListNode *left_partition = &new_head;
        ListNode middle; // sentinel
        ListNode *right_partition = &middle;
        
        for (;head != nullptr; head = head->next) {
            if (head->val < x) {
                left_partition->next = new ListNode(head->val, &middle);
                left_partition = left_partition->next;
            } else {
                right_partition->next = new ListNode(head->val);
                right_partition = right_partition->next;
            }
        }

        left_partition->next = middle.next;
        return new_head.next;
    }
};
