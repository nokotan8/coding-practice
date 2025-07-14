#include "../definitions.hpp"

class Solution {
  public:
    int getDecimalValue(ListNode *head) {
        int val = 0;

        while (head != nullptr) {
            val <<= 1;
            val |= head->val;
            head = head->next;
        }

        return val;
    }
};
