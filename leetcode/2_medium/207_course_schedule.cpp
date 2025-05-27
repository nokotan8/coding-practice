#include <vector>

#define UNVISITED 0
#define VISITING 1
#define VISITED 2

class Solution {
  public:
    // no cycle => true, cycle detected => false
    bool dfs(int v, std::vector<std::vector<int>> &graph,
             std::vector<int> &visited) {
        visited[v] = VISITING;
        for (int adj : graph[v]) {
            if (visited[adj] == VISITING)
                return false;
            else if (visited[adj] == UNVISITED) {
                if (dfs(adj, graph, visited) == false) {
                    return false;
                }
            }
        }

        visited[v] = VISITED;
        return true;
    }

    bool canFinish(int n, std::vector<std::vector<int>> &prereqs) {
        std::vector<std::vector<int>> graph(n);
        std::vector<int> visited(n, UNVISITED);
        for (auto &p : prereqs)
            graph[p[0]].push_back(p[1]);

        for (int i = 0; i < n; i++) {
            if (visited[i] == UNVISITED) {
                if (dfs(i, graph, visited) == false)
                    return false;
            }
        }

        return true;
    }
};
