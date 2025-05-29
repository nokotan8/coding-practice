#include <queue>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr)
            return {};
        std::queue<TreeNode *> q;
        std::vector<std::vector<int>> res;
        int lvl = 0;
        q.push(root);
        while (q.empty() == false) {
            res.push_back({});
            int num = q.size();
            for (int i = 0; i < num; i++) {
                TreeNode *curr = q.front();
                q.pop();
                res[lvl].push_back(curr->val);
                if (curr->left != nullptr)
                    q.push(curr->left);
                if (curr->right != nullptr)
                    q.push(curr->right);
            }
            lvl++;
        }

        return res;
    }
};
