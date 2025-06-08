#include "../definitions.hpp"
#include <algorithm>
#include <climits>

class Solution {
  public:
    int max_sum = INT_MIN;
    // Returns max sum of path ending at curr
    int max_sum_dfs(TreeNode *curr) {
        if (curr == nullptr)
            return 0;

        int lmax = std::max(max_sum_dfs(curr->left), 0);
        int rmax = std::max(max_sum_dfs(curr->right), 0);

        max_sum = std::max(max_sum, curr->val + lmax + rmax);

        return curr->val + std::max(lmax, rmax);
    }

    int maxPathSum(TreeNode *root) {
        max_sum_dfs(root);

        return max_sum;
    }
};
