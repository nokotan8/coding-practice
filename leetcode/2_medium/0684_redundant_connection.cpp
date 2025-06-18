#include <vector>

class union_find {
  public:
    union_find(int n) {
        root.resize(n);
        height.resize(n, 1);
        for (int i = 0; i < n; i++) {
            root[i] = i;
        }
    }

    int find(int node) {
        int node_parent = root[node];
        while (root[node_parent] != node_parent) {
            node_parent = root[node_parent];
        }

        root[node] = node_parent;
        return node_parent;
    }

    bool join(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);

        if (root1 == root2) {
            return false;
        } else {
            if (height[root1] < height[root2]) {
                root[root1] = root2;
            } else if (height[root1] > height[root2]) {
                root[root2] = root1;
            } else {
                root[root1] = root2;
                height[root2]++;
            }

            return true;
        }
    }

  private:
    std::vector<int> root;
    std::vector<int> height;
};

class Solution {
  public:
    std::vector<int>
    findRedundantConnection(std::vector<std::vector<int>> &edges) {
        const int n = edges.size();
        union_find uf(n + 1);
        for (auto &edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            if (uf.join(node1, node2) == false) {
                return edge;
            }
        }

        return {};
    }
};
