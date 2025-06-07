#include "../definitions.hpp"
#include <algorithm>

class Solution {
  public:
    int max_dist = 0;
    int traverse(TreeNode *curr) {
        if (curr == nullptr)
            return 0;

        int lheight = traverse(curr->left);
        int rheight = traverse(curr->right);

        max_dist = std::max(max_dist, lheight + rheight);

        return std::max(lheight, rheight) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root) {
        traverse(root);

        return max_dist;
    }
};
