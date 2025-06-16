#include <algorithm>
#include <functional>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define VALID(r, c, n) ((r) >= 0 && (r) < (n) && (c) >= 0 && (c) < (n))

class Solution {
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    int swimInWater(vector<vector<int>> &grid) {
        const size_t n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        while (pq.empty() == false) {
            auto [d, row, col] = pq.top();
            pq.pop();

            if (row == n - 1 && col == n - 1) {
                return d;
            }

            for (auto [x, y] : directions) {
                if (VALID(row + x, col + y, n) &&
                    visited[row + x][col + y] == false) {
                    visited[row + x][col + y] = true;
                    pq.push({max(grid[row + x][col + y], d), row + x, col + y});
                }
            }
        }

        return -1;
    }
};
