
#include "../definitions.hpp"
#include <stdlib.h>

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode();
        ListNode *curr = head;
        head->val = 0;
        int carry = 0;

        while (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum %= 10;
            curr->next = new ListNode(sum);
            curr = curr->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 == nullptr) {
            l1 = l2;
        }
        while (l1) {
            int sum = l1->val + carry;
            carry = sum / 10;
            sum %= 10;
            curr->next = new ListNode(sum);
            curr = curr->next;

            l1 = l1->next;
        }
        if (carry) {
            curr->next = new ListNode(carry);
        }

        ListNode *ret = head->next;
        delete head;
        return ret;
    }
};
