#include "../definitions.hpp"
#include <algorithm>
#include <cstdlib>
#include <utility>

class Solution {
    // {height, is_balanced}
    std::pair<int, bool> traverse(TreeNode *curr) {
        if (curr == nullptr) {
            return {0, true};
        }

        auto [l, l_bal] = traverse(curr->left);
        auto [r, r_bal] = traverse(curr->right);
        int height = std::max(l, r) + 1;
        if (l_bal == false || r_bal == false || std::abs(l - r) > 1) {
            return {height, false};
        } else {
            return {height, true};
        }

    }
public:
    bool isBalanced(TreeNode* root) {
        return traverse(root).second;
    }
};
