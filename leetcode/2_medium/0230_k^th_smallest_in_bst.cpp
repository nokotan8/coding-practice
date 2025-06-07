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
    int curr = 0;
    int kthSmallest(TreeNode *root, int k) {
        // In-order traversal (left -> root -> right)
        if (root->left != nullptr) {
            int res = kthSmallest(root->left, k);
            if (res != -1)
                return res;
        }

        curr++;
        if (curr == k)
            return root->val;

        if (root->right != nullptr) {
            int res = kthSmallest(root->right, k);
            if (res != -1)
                return res;
        }

        return -1;
    }
};
