#include <algorithm>
#include <array>
#include <cstdlib>
#include <vector>

class union_find {
    std::vector<int> parent, height;

  public:
    union_find(int n) {
        parent.resize(n);
        height.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            height[i] = 1;
        }
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        } else {
            parent[i] = find(parent[i]);
            return parent[i];
        }
    }

    bool unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2) {
            if (height[s1] < height[s2])
                parent[s1] = s2;
            else if (height[s1] > height[s2])
                parent[s2] = s1;
            else
                parent[s2] = s1, height[s1]++;
            return true;
        } else {
            return false;
        }
    }
};

class Solution {
  public:
    int minCostConnectPoints(std::vector<std::vector<int>> &points) {
        std::vector<std::array<int, 3>> edges;
        const int n = points.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        std::sort(edges.begin(), edges.end());
        union_find uf(n);

        int res = 0;
        int cnt = 0;
        for (auto &[dist, x, y] : edges) {
            if (uf.unite(x, y)) {
                res += dist;
                cnt++;
                if (cnt == n - 1) {
                    break;
                }
            }
        }

        return res;
    }
};
