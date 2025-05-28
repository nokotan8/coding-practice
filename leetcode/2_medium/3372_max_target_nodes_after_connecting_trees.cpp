#include <algorithm>
#include <vector>
class Solution {
  public:
    void dfs(int src, int v, int prev, int max_dist, std::vector<int> &target,
             std::vector<std::vector<int>> &tree) {
        if (max_dist < 0)
            return;

        target[src]++;
        for (int adj : tree[v]) {
            if (adj != prev)
                dfs(src, adj, v, max_dist - 1, target, tree);
        }
    }

    std::vector<int> maxTargetNodes(std::vector<std::vector<int>> &edges1,
                                    std::vector<std::vector<int>> &edges2,
                                    int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        std::vector<std::vector<int>> tree1(n);
        std::vector<std::vector<int>> tree2(m);
        std::vector<int> target1(n, 0);
        std::vector<int> target2(m, 0);

        for (auto &edge : edges1) {
            tree1[edge[0]].push_back(edge[1]);
            tree1[edge[1]].push_back(edge[0]);
        }
        for (auto &edge : edges2) {
            tree2[edge[0]].push_back(edge[1]);
            tree2[edge[1]].push_back(edge[0]);
        }

        int max_target2 = 0;
        for (int j = 0; j < m; j++) {
            dfs(j, j, j, k - 1, target2, tree2);
            max_target2 = std::max(max_target2, target2[j]);
        }
        for (int i = 0; i < n; i++) {
            dfs(i, i, i, k, target1, tree1);
            target1[i] += max_target2;
        }

        return target1;
    }
};
