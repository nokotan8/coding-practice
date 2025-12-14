#include "../definitions.hpp"
#include <climits>

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return recurse(root, LONG_MIN, LONG_MAX);
    }

    bool recurse(TreeNode *curr, long min, long max) {
        if (curr == nullptr) {
            return true;
        }

        if (curr->val <= min || curr->val >= max) {
            return false;
        }

        return recurse(curr->left, min, curr->val) &&
          recurse(curr->right, curr->val, max);

    }
};
