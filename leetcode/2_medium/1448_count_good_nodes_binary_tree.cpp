#include "../definitions.hpp"
#include <algorithm>
#include <climits>
class Solution {
  public:
    int dfs(TreeNode *curr, int max) {
        if (curr == nullptr)
            return 0;

        int res = curr->val >= max ? 1 : 0;

        int new_max = std::max(curr->val, max);
        res += dfs(curr->left, new_max);
        res += dfs(curr->right, new_max);

        return res;
    }
    int goodNodes(TreeNode *root) {
        return dfs(root, INT_MIN);
    }
};
