#include <utility>
#include <vector>
class Solution {
  private:
    std::vector<std::pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void recurse(std::vector<std::vector<char>> &grid, int row, int col) {
        grid[row][col] = '2';

        for (auto [x, y] : directions) {
            int i = row + x;
            int j = col + y;

            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() &&
                grid[i][j] == '1') {
                recurse(grid, i, j);
            }
        }
    }

  public:
    int numIslands(std::vector<std::vector<char>> &grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    res++;
                    recurse(grid, i, j);
                }
            }
        }

        return res;
    }
};
