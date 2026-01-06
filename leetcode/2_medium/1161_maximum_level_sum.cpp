#include "../definitions.hpp"

#include <climits>
#include <queue>

class Solution {
  public:
    int maxLevelSum(TreeNode *root) {
        std::queue<TreeNode *> q;
        q.push(root);

        long long max_sum = LONG_LONG_MIN;
        int max_lvl = 0;
        int curr_lvl = 1;

        while (q.empty() == false) {
            long long sum = 0;
            size_t cnt = q.size();
            for (size_t i = 0; i < cnt; i++) {
                TreeNode *curr = q.front();
                q.pop();
                sum += curr->val;

                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }

            if (sum > max_sum) {
                max_sum = sum;
                max_lvl = curr_lvl;
            }
            curr_lvl++;
        }

        return max_lvl;
    }
};
