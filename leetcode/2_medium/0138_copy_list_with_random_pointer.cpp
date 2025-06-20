#include "../definitions.hpp"
#include <unordered_map>

class Solution {
  public:
    Node *copyRandomList(Node *head) {
        std::unordered_map<Node *, Node *> new_node;
        new_node[nullptr] = nullptr;

        Node dummy(0);
        Node *curr = head;
        Node *new_prev = &dummy;
        Node *new_curr = nullptr;

        while (curr != nullptr) {
            if (new_node.find(curr) == new_node.end()) {
                new_curr = new Node(curr->val);
                new_node[curr] = new_curr;
            } else {
                new_curr = new_node[curr];
            }
            new_prev->next = new_curr;

            if (new_node.find(curr->random) == new_node.end()) {
                new_node[curr->random] = new Node(curr->random->val);
            }
            new_curr->random = new_node[curr->random];

            new_prev = new_curr;
            curr = curr->next;
        }

        return dummy.next;
    }
};
