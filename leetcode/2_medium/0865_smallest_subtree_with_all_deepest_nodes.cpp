#include "../definitions.hpp"
#include <utility>

/* One pass */
class Solution {
    std::pair<TreeNode *, int> dfs(TreeNode *curr) {
        if (curr == nullptr) {
            return {nullptr, 0};
        }

        std::pair<TreeNode *, int> l = dfs(curr->left);
        std::pair<TreeNode *, int> r = dfs(curr->right);
        if (l.second > r.second) {
            return {l.first, l.second + 1};
        } else if (l.second < r.second) {
            return {r.first, r.second + 1};
        } else {
            return {curr, l.second + 1};
        }
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};

/* Two pass */
// class Solution {
//     int max_lvl = 0;
//     int max_lvl_cnt = 0;
//     TreeNode *res = nullptr;
//
//     void find_max_lvl(TreeNode *curr, int lvl) {
//         if (curr == nullptr) {
//             return;
//         }
//
//         find_max_lvl(curr->left, lvl + 1);
//         find_max_lvl(curr->right, lvl + 1);
//
//         if (lvl > max_lvl) {
//             max_lvl = lvl;
//             max_lvl_cnt = 1;
//         } else if (lvl == max_lvl) {
//             max_lvl_cnt++;
//         }
//     }
//
//     int dfs(TreeNode *curr, int lvl) {
//         if (curr == nullptr) {
//             return 0;
//         }
//         
//         int num_deepest = 0;
//         num_deepest += dfs(curr->left, lvl + 1);
//         num_deepest += dfs(curr->right, lvl + 1);
//         if (res != nullptr) {
//             return 0;
//         }
//
//         if (lvl == max_lvl) {
//             num_deepest++;
//         }
//         if (num_deepest == max_lvl_cnt) {
//             res = curr;
//         }
//
//         return num_deepest;
//     }
//
// public:
//     TreeNode* subtreeWithAllDeepest(TreeNode* root) {
//         find_max_lvl(root, 1);
//
//         dfs(root, 1);
//
//         return res;
//     }
// };

