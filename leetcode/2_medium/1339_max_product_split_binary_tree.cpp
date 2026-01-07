#include "../definitions.hpp"
#include <algorithm>

class Solution {
private:
    unsigned long max = 0;
    unsigned long total_sum = 0;
public:
    unsigned long sum(TreeNode *curr) {
        return curr->val + (curr->left ? sum(curr->left) : 0) + (curr->right ? sum(curr->right) : 0);
    }

    unsigned long dfs(TreeNode *curr) {
        unsigned long curr_sum = curr->val + (curr->left ? dfs(curr->left) : 0) + (curr->right ? dfs(curr->right) : 0);
        max = std::max(max, (total_sum - curr_sum) * curr_sum);

        return curr_sum;
    }

    int maxProduct(TreeNode *root) {
        total_sum = sum(root);
        dfs(root);

        return max % (int)(1e9 + 7);
    }
};
