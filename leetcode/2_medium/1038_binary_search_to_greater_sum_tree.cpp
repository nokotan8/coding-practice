/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int currSum = 0;

public:
    TreeNode *bstToGst(TreeNode *root) {
        recurse(root);
        return root;
    }

    void recurse(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        recurse(node->right);
        currSum += node->val;
        node->val = currSum;
        recurse(node->left);

        return;
    }
};
