#include <climits>
#include <vector>
class Solution {
  public:
    void dfs(std::vector<int> &edges, int v, int dist,
             std::vector<int> &dists) {
        dists[v] = dist;
        if (edges[v] != -1 && dists[edges[v]] == -1) {
            dfs(edges, edges[v], dist + 1, dists);
        }
    }
    int closestMeetingNode(std::vector<int> &edges, int node1, int node2) {
        const size_t n = edges.size();
        std::vector<int> dists_from_1(n, -1);
        std::vector<int> dists_from_2(n, -1);

        dfs(edges, node1, 0, dists_from_1);
        dfs(edges, node2, 0, dists_from_2);

        int min = INT_MAX;
        int min_i = -1;
        for (size_t i = 0; i < n; i++) {
            if (dists_from_1[i] != -1 && dists_from_2[i] != -1) {
                int max_dist = std::max(dists_from_1[i], dists_from_2[i]);
                if (min > max_dist) {
                    min = max_dist;
                    min_i = i;
                }
            }
        }

        return min_i;
    }
};
