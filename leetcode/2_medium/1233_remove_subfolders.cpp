#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class node {
  public:
    bool end;
    std::unordered_map<std::string, node *> children;

    node() : end(false) {}
};

class trie {
  private:
    void delete_node(node *n) {
        if (n == nullptr) {
            return;
        }
        for (auto [_, next] : n->children) {
            delete_node(next);
        }

        delete n;
    }

  public:
    trie() {
        root = new node();
    }

    ~trie() {
        delete_node(root);
    }

    void insert(std::string s) {
        std::stringstream ss(s);
        std::string f;
        node *curr = root;
        while (std::getline(ss, f, '/')) {
            if (curr->children.find(f) == curr->children.end()) {
                curr->children[f] = new node();
            }
            curr = curr->children[f];
        }
        curr->end = true;
    }

    bool is_subfolder(std::string s) {
        std::stringstream ss(s);
        std::string f;
        node *curr = root;
        while (std::getline(ss, f, '/')) {
            if (curr->end == true) {
                return true;
            }
            curr = curr->children[f];
        }

        return false;
    }

  private:
    node *root;
};

class Solution {
  public:
    std::vector<std::string>
    removeSubfolders(std::vector<std::string> &folder) {
        trie t;
        std::vector<std::string> res;
        for (auto &f : folder) {
            t.insert(f.substr(1));
        }
        for (auto &f : folder) {
            if (t.is_subfolder(f.substr(1)) == false) {
                res.push_back(f);
            }
        }

        return res;
    }
};
