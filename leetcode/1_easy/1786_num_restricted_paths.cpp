#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
class Solution {
  public:
    long mod = 1e9 + 7;
    long countPaths(std::vector<std::vector<std::pair<int, int>>> &graph,
                    std::vector<long> dp, std::vector<int> &dist, int src) {
        if (src == 1)
            return 1;

        if (dp[src] != -1) {
            return dp[src];
        }

        long count = 0;
        for (auto &n : graph[src]) {
            if (dist[n.first] > dist[src]) {
                count =
                    (count % mod + countPaths(graph, dp, dist, n.first) % mod);
            }
        }

        return dp[src] = count % mod;
    }
    int countRestrictedPaths(int n, std::vector<std::vector<int>> &edges) {
        std::vector<std::vector<std::pair<int, int>>> graph(
            n + 1, std::vector<std::pair<int, int>>());

        for (auto &edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        // Dijkstras
        std::vector<int> dist(n + 1, INT_MAX);
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
                            std::greater<std::vector<int>>>
            pq;

        dist[n] = 0;
        pq.push({0, n});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            for (auto &n : graph[curr[1]]) {
                if (curr[0] + n.second < dist[n.first]) {
                    dist[n.first] = curr[0] + n.second;
                    pq.push({dist[n.first], n.first});
                }
            }
        }

        for (int i = 1; i < graph.size(); i++) {
            std::cout << i << " -> ";
            for (auto n : graph[i]) {
                std::cout << n.first << ',' << n.second << ' ';
            }

            std::cout << '\n';
        }

        // Count paths from 1->n in DAG
        std::vector<long> dp(n + 1, -1);

        return countPaths(graph, dp, dist, n);
    }
};
