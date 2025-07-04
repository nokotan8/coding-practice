#include "../definitions.hpp"
#include <unordered_map>
#include <vector>

class Solution {
  private:
    int root_idx = 0;

    TreeNode *recurse(std::vector<int> &preorder,
                      std::unordered_map<int, int> &inorder_idxs, int l,
                      int r) {
        int root = preorder[root_idx];

        TreeNode *curr = new TreeNode(root);

        int lchild_idx = inorder_idxs[root] - 1;
        if (lchild_idx >= l) {
            root_idx++;
            curr->left = recurse(preorder, inorder_idxs, l, lchild_idx);
        }
        int rchild_idx = inorder_idxs[root] + 1;
        if (rchild_idx <= r) {
            root_idx++;
            curr->right = recurse(preorder, inorder_idxs, rchild_idx, r);
        }

        return curr;
    }

  public:
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
        std::unordered_map<int, int> inorder_idxs;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_idxs[inorder[i]] = i;
        }

        return recurse(preorder, inorder_idxs, 0, inorder.size() - 1);
    }
};
