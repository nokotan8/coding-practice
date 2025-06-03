#include "../definitions.hpp"
#include <queue>
class Solution {
  public:
    bool is_identical(TreeNode *node1, TreeNode *node2) {
        if (node1 == nullptr || node2 == nullptr)
            return node1 == node2;
        else if (node1->val != node2->val)
            return false;

        return is_identical(node1->left, node2->left) &&
               is_identical(node1->right, node2->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr) {
            return subRoot == nullptr;
        }

        std::queue<TreeNode *> q;
        q.push(root);

        while (q.empty() == false) {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->val == subRoot->val) {
                if (is_identical(curr, subRoot))
                    return true;
            }

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        return false;
    }
};
