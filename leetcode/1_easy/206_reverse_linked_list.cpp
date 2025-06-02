#include "../definitions.hpp"

/**
 * Iteration
 */
class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

/**
 * Iteration but worse
 */
// #include <stack>
// class Solution {
//   public:
//     ListNode *reverseList(ListNode *head) {
//         if (head == nullptr)
//             return nullptr;
//
//         std::stack<int> nodes;
//         ListNode *curr = head;
//         while (curr != nullptr) {
//             nodes.push(curr->val);
//             curr = curr->next;
//         }
//
//         curr = head;
//         while (nodes.empty() == false) {
//             curr->val = nodes.top();
//             nodes.pop();
//             curr = curr->next;
//         }
//
//         return head;
//     }
// };
