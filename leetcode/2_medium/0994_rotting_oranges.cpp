#include <queue>
#include <utility>
#include <vector>

class Solution {
  public:
    int orangesRotting(std::vector<std::vector<int>> &grid) {
        size_t m = grid.size();
        size_t n = grid[0].size();
        int fresh_oranges = 0;
        std::queue<std::pair<int, int>> q;

        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                switch (grid[i][j]) {
                    case 1:
                        fresh_oranges++;
                        break;
                    case 2:
                        q.push({i, j});
                        break;
                    default:
                        break;
                }
            }
        }

        int minutes = 0;
        while (fresh_oranges && q.empty() == false) {
            size_t cnt = q.size();

            for (size_t i = 0; i < cnt; i++) {
                auto [x, y] = q.front();
                q.pop();

                if (x > 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2;
                    q.push({x - 1, y});
                    fresh_oranges--;
                }
                if (x < m - 1 && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2;
                    q.push({x + 1, y});
                    fresh_oranges--;
                }
                if (y > 0 && grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 2;
                    q.push({x, y - 1});
                    fresh_oranges--;
                }
                if (y < n - 1 && grid[x][y + 1] == 1) {
                    grid[x][y + 1] = 2;
                    q.push({x, y + 1});
                    fresh_oranges--;
                }
            }

            minutes++;
        }

        return fresh_oranges ? -1 : minutes;
    }
};
