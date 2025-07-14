#include "../definitions.hpp"
#include <vector>

class Solution {
  private:
    std::vector<int> res;

    void traverse(TreeNode *curr, int lvl) {
        if (curr == nullptr) {
            return;
        }
        if (lvl == res.size()) {
            res.push_back(curr->val);
        }

        traverse(curr->right, lvl + 1);
        traverse(curr->left, lvl + 1);
    }

  public:
    std::vector<int> rightSideView(TreeNode *root) {
        traverse(root, 0);
        return res;
    }
};
