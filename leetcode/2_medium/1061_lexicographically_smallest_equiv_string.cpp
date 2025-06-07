#include <string>

class Solution {
  public:
    std::string smallestEquivalentString(std::string s1, std::string s2,
                                         std::string baseStr) {
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for (size_t i = 0; i < s1.size(); i++) {
            join(s1[i] - 'a', s2[i] - 'a');
        }

        for (char &c : baseStr) {
            c = (char)('a' + find(c - 'a'));
        }

        return baseStr;
    }

  private:
    // Modified from:
    // https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm
    int parent[26];

    int find(int i) {
        int root = parent[i];
        if (parent[root] != root) {
            parent[i] = find(root);
            return parent[i];
        }

        return root;
    }

    void join(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i == root_j)
            return;
        else if (root_i <= root_j)
            parent[root_j] = root_i;
        else
            parent[root_i] = root_j;
    }
};
