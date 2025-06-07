#include "../definitions.hpp"

/**
 * Divide & conquer
 * O(nlog(k)) where:
 *  n = total # of nodes
 *  k = # of lists
 */
#include <vector>

class Solution {
  public:
    ListNode *merge_2_lists(ListNode *list1, ListNode *list2) {
        ListNode *head = new ListNode(0);

        ListNode *curr1 = list1;
        ListNode *curr2 = list2;

        ListNode *curr = head;
        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->val < curr2->val) {
                curr->next = curr1;
                curr1 = curr1->next;
            } else {
                curr->next = curr2;
                curr2 = curr2->next;
            }
            curr = curr->next;
        }

        if (curr1 == nullptr) {
            curr->next = curr2;
        } else {
            curr->next = curr1;
        }

        ListNode *res = head->next;
        delete head;

        return res;
    }

    ListNode *divide(std::vector<ListNode *> &lists, size_t l, size_t r) {
        if (l > r)
            return nullptr;
        else if (l == r)
            return lists[l];

        size_t m = (l + r) / 2;

        ListNode *left = divide(lists, l, m);
        ListNode *right = divide(lists, m + 1, r);

        return merge_2_lists(left, right);
    }

    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return nullptr;

        return divide(lists, 0, lists.size() - 1);
    }
};

/**
 * Idk what it's called, two at a time?
 * O(nk) where:
 *  n = total # of nodes
 *  k = # of lists
 */
// #include <vector>
//
// class Solution {
//   public:
//     ListNode *merge_2_lists(ListNode *list1, ListNode *list2) {
//         ListNode *head = new ListNode(0);
//
//         ListNode *curr1 = list1;
//         ListNode *curr2 = list2;
//
//         ListNode *curr = head;
//         while (curr1 != nullptr && curr2 != nullptr) {
//             if (curr1->val < curr2->val) {
//                 curr->next = curr1;
//                 curr1 = curr1->next;
//             } else {
//                 curr->next = curr2;
//                 curr2 = curr2->next;
//             }
//             curr = curr->next;
//         }
//
//         if (curr1 == nullptr) {
//             curr->next = curr2;
//         } else {
//             curr->next = curr1;
//         }
//
//         ListNode *res = head->next;
//         delete head;
//
//         return res;
//     }
//
//     ListNode *mergeKLists(std::std::vector<ListNode *> &lists) {
//         const size_t k = lists.size();
//         if (k == 0)
//             return nullptr;
//         else if (k == 1)
//             return lists[0];
//
//         for (size_t i = 0; i < k - 1; i++) {
//             lists[i + 1] = merge_2_lists(lists[i], lists[i + 1]);
//             ListNode *curr = lists[i + 1];
//         }
//
//         return lists[k - 1];
//     }
// };
