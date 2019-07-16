/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned long n, n1, n2, factor;
        n1 = 0;
        n2 = 0;
        factor = 1;
        while (l1 != NULL)
        {
            n1 += l1->val * factor;

            factor *= 10;
            l1 = l1->next;
        }
        factor = 1;
        while (l2 != NULL)
        {
            n2 += l2->val * factor;

            factor *= 10;
            l2 = l2->next;
        }
        n = n1 + n2;
        ListNode *root = new ListNode(n % 10);
        n /= 10;

        ListNode *node = root;
        while (n != 0)
        {
            node->next = new ListNode(n % 10);
            n /= 10;
            node = node->next;
        }

        return root;
    }
};
