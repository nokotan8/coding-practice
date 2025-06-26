#include "../definitions.hpp"
#include <sstream>
#include <string>
#include <vector>

class Codec {
  public:
    std::string serialize(TreeNode *root) {
        std::string res = ser_traverse(root);

        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data) {
        std::vector<int> nodes;
        std::stringstream data_stream(data);
        std::string node_str;

        while (getline(data_stream, node_str, ',')) {
            if (node_str[0] == 'n') {
                nodes.push_back(1001); // Maximum node value is 1000
            } else {
                nodes.push_back(std::stoi(node_str));
            }
        }

        int idx = 0;
        return deser_traverse(nodes, idx);
    }

  private:
    std::string ser_traverse(TreeNode *curr) {
        if (curr == nullptr) {
            return "n,";
        }

        std::string res = std::to_string(curr->val);
        res += ',';

        res += ser_traverse(curr->left);
        res += ser_traverse(curr->right);

        return res;
    }

    TreeNode *deser_traverse(std::vector<int> &nodes, int &idx) {
        if (nodes[idx] == 1001) {
            idx++;
            return nullptr;
        }

        TreeNode *curr = new TreeNode(nodes[idx]);
        idx++;
        curr->left = deser_traverse(nodes, idx);
        curr->right = deser_traverse(nodes, idx);

        return curr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
