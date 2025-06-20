#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>>
    pacificAtlantic(std::vector<std::vector<int>> &heights) {
        int m = heights.size();
        int n = heights[0].size();

        std::vector<std::vector<bool>> can_reach_pacific(
            m, std::vector<bool>(n, false));
        std::vector<std::vector<bool>> can_reach_atlantic(
            m, std::vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, can_reach_pacific);
            dfs(heights, i, n - 1, can_reach_atlantic);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, can_reach_pacific);
            dfs(heights, m - 1, j, can_reach_atlantic);
        }

        std::vector<std::vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (can_reach_pacific[i][j] && can_reach_atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

  private:
    std::vector<std::vector<int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(std::vector<std::vector<int>> &heights, int row, int col,
             std::vector<std::vector<bool>> &can_reach) {
        can_reach[row][col] = true;

        for (auto &dir : directions) {
            int x = row + dir[0];
            int y = col + dir[1];

            if (x >= 0 && x < heights.size() && y >= 0 &&
                y < heights[0].size() && can_reach[x][y] == false &&
                heights[x][y] >= heights[row][col]) {
                dfs(heights, x, y, can_reach);
            }
        }
    }
};
