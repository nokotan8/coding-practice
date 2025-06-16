#include "../definitions.hpp"

class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy(0);
        ListNode *group_start = head;
        ListNode *prev_group_end = &dummy;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next;

        while (1) {
            int count = 1;
            while (curr != nullptr && count < k) {
                curr = curr->next;
                count++;
            }

            if (curr != nullptr) {
                curr = group_start;
                prev = nullptr;
                for (int i = 0; i < k; i++) {
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }

                prev_group_end->next = prev;
                prev_group_end = group_start;
                group_start = curr;
            } else {
                prev_group_end->next = group_start;
                break;
            }
        }

        return dummy.next;
    }
};
