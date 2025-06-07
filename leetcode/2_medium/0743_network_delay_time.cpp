#include <algorithm>
#include <climits>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
class Solution {
  public:
    int networkDelayTime(std::vector<std::vector<int>> &times, int n, int k) {
        std::vector<std::vector<std::pair<int, int>>> graph(n + 1);
        for (auto &time : times) {
            int src = time[0];
            int dst = time[1];
            int travel_time = time[2];
            graph[src].push_back({dst, travel_time});
        }

        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>>
            pq;
        std::vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while (pq.empty() == false) {
            auto [distance, v] = pq.top();
            pq.pop();

            for (auto [adj, weight] : graph[v]) {
                if (dist[v] + weight < dist[adj]) {
                    dist[adj] = distance + weight;
                    pq.push({dist[adj], adj});
                }
            }
        }

        // There is no node 0, so ignore it
        int res = *std::max_element(dist.begin() + 1, dist.end());

        return res == INT_MAX ? -1 : res;
    }
};
