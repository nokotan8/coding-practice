#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<int> findOrder(int n,
                               std::vector<std::vector<int>> &prerequisites) {
        std::vector<std::vector<int>> graph(n);
        std::vector<int> indegree(n, 0);
        for (auto &prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }

        std::queue<int> q;
        for (size_t i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        std::vector<int> res;
        while (q.empty() == false) {
            int v = q.front();
            q.pop();
            res.push_back(v);

            for (int adj : graph[v]) {
                if (indegree[adj]) {
                    indegree[adj]--;
                    if (indegree[adj] == 0)
                        q.push(adj);
                }
            }
        }

        if (res.size() == n)
            return res;
        else
            return {};
    }
};
