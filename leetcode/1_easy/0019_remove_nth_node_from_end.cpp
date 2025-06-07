// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *curr = head;
        ListNode *n_behind = head;

        int i = 0;
        for (; i < n && curr->next != nullptr; i++)
            curr = curr->next;

        if (curr == n_behind)
            return nullptr;
        else if (i != n)
            return head->next;

        while (curr->next != nullptr) {
            curr = curr->next;
            n_behind = n_behind->next;
        }

        ListNode *tmp = n_behind->next->next;
        delete n_behind->next;
        n_behind->next = tmp;

        return head;
    }
};
