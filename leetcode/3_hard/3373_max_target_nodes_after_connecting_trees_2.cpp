#include <algorithm>
#include <vector>
class Solution {
  public:
    void dfs(int v, int prev, std::vector<std::vector<int>> &tree,
             std::vector<bool> &parity, int &even_c, int &odd_c) {
        parity[v] ? odd_c++ : even_c++;
        for (int adj : tree[v]) {
            if (adj != prev) {
                parity[adj] = !parity[v];
                dfs(adj, v, tree, parity, even_c, odd_c);
            }
        }

        return;
    }

    std::vector<int> maxTargetNodes(std::vector<std::vector<int>> &edges1,
                                    std::vector<std::vector<int>> &edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        std::vector<std::vector<int>> tree1(n);
        std::vector<std::vector<int>> tree2(m);
        std::vector<int> res(n, 0);
        std::vector<bool> parity(std::max(n, m));

        for (auto &edge : edges1) {
            tree1[edge[0]].push_back(edge[1]);
            tree1[edge[1]].push_back(edge[0]);
        }
        for (auto &edge : edges2) {
            tree2[edge[0]].push_back(edge[1]);
            tree2[edge[1]].push_back(edge[0]);
        }

        int even_c = 0, odd_c = 0;
        parity[0] = false;
        dfs(0, 0, tree2, parity, even_c, odd_c);
        int max_second = std::max(even_c, odd_c);

        even_c = 0;
        odd_c = 0;
        dfs(0, 0, tree1, parity, even_c, odd_c);
        for (int i = 0; i < n; i++) {
            res[i] = (parity[i] ? odd_c : even_c) + max_second;
        }

        return res;
    }
};
