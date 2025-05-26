#include <algorithm>
#include <climits>
#include <string>
#include <unordered_set>
#include <vector>

#define UNVISITED 0
#define VISITING 1
#define VISITED 2

class Solution {
  public:
    std::unordered_set<int> colorset;

    int dfs(int v, std::vector<std::vector<int>> &graph, std::string &colors,
            std::vector<int> &visited, std::vector<std::vector<int>> &dp) {
        if (visited[v] == UNVISITED) {
            visited[v] = VISITING;
            for (int adj : graph[v]) {
                if (visited[adj] == VISITING)
                    return INT_MAX;
                else if (visited[adj] == UNVISITED) {
                    if (dfs(adj, graph, colors, visited, dp) == INT_MAX)
                        return INT_MAX;
                }
                for (int c : colorset) {
                    dp[v][c] = std::max(dp[v][c], dp[adj][c]);
                }
            }
            dp[v][colors[v] - 'a']++;
            visited[v] = VISITED;
        }

        return visited[v] == VISITED ? dp[v][colors[v] - 'a'] : INT_MAX;
    };

    int largestPathValue(std::string colors,
                         std::vector<std::vector<int>> &edges) {
        const int n = colors.size();
        for (char c : colors)
            colorset.insert(c - 'a');

        std::vector<std::vector<int>> graph(n);
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        // dp[i][j] = maximum number of nodes of colour j in any path
        // starting from vertex i
        std::vector<std::vector<int>> dp(n, std::vector<int>(26));
        std::vector<int> visited(n, UNVISITED);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = std::max(ans, dfs(i, graph, colors, visited, dp));
            if (ans == INT_MAX)
                return -1;
        }

        return ans;
    }
};
