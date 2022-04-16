#include <iostream>
#include <vector>

#include "rotate-list.h"
#include "src/helpers/list-node.h"

using namespace std;

leetcode::ListNode *
leetcode::Solution::rotateRight(leetcode::ListNode *input_head, int k) {
  if (k == 0 || input_head == nullptr || input_head->next == nullptr) {
    return input_head;
  }
  ListNode *head = new ListNode(input_head->val);
  ListNode *tail = head;

  // copy input list and compute length
  int length = 1;
  for (ListNode *element = input_head->next; element != nullptr; ++length) {
    ListNode *current = new ListNode(element->val);
    tail->next = current;
    tail = current;
    element = element->next;
  }

  const int new_head_index =
      k % length; // use the computed length to cut cycles short
  if (k == 0) {
    return head;
  }

  const int pivot_index = length - new_head_index - 1;
  ListNode *pivot = head;
  for (int counter = 0; counter < pivot_index; ++counter) {
    pivot = pivot->next;
  }

  tail->next = head;
  ListNode *rotate_start = pivot->next;
  pivot->next = nullptr;
  return rotate_start;
}
