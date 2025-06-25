#include <string>

struct Node {
  public:
    bool end;
    Node *children[26];

    Node() {
        end = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
class Trie {
  private:
    Node *root;

  public:
    Trie() {
        root = new Node();
    }

    void insert(std::string word) {
        Node *curr = root;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new Node();
            }
            curr = curr->children[c - 'a'];
        }
        curr->end = true;
    }

    bool search(std::string word) {
        Node *curr = root;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }

        return curr->end == true;
    }

    bool startsWith(std::string prefix) {
        Node *curr = root;
        for (char c : prefix) {
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
