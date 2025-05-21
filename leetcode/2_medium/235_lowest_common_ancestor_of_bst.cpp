// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *node, TreeNode *p, TreeNode *q) {
        if (p->val > q->val) {
            TreeNode *tmp = q;
            q = p;
            p = tmp;
        }

        return traverse(node, p, q);
    }

    TreeNode *traverse(TreeNode *node, TreeNode *p, TreeNode *q) {
        if ((node->val > p->val && node->val < q->val) || node->val == q->val ||
            node->val == p->val) {
            return node;
        } else if (node->val < p->val) {
            return traverse(node->right, p, q);
        } else {
            return traverse(node->left, p, q);
        }
    }
};
