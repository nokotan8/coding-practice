#include <unordered_map>
#include <vector>
// Definition for a Node.
class Node {
  public:
    int val;
    std::vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node *>();
    }
    Node(int _val, std::vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
  public:
    std::unordered_map<int, Node *> mp;
    Node *cloneGraph(Node *node) {
        if (node == nullptr)
            return nullptr;

        Node *copy = new Node(node->val);
        mp[copy->val] = copy;
        for (Node *adj : node->neighbors) {
            if (mp.count(adj->val) == 0)
                cloneGraph(adj);
            mp[adj->val]->neighbors.push_back(copy);
        }

        return copy;
    }
};
