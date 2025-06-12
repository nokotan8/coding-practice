#include <algorithm>
#include <utility>
#include <vector>

class Solution {
  public:
    int longestIncreasingPath(std::vector<std::vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        dp = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));

        int max_path = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                max_path = std::max(max_path, dfs(matrix, i, j));
            }
        }

        return max_path;
    }

  private:
    std::vector<std::vector<int>> dp;
    std::vector<std::pair<int, int>> four_adj = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int dfs(std::vector<std::vector<int>> &matrix, int r, int c) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (dp[r][c]) {
            return dp[r][c];
        }

        dp[r][c] = 1;
        for (auto [x, y] : four_adj) {
            if (r + x >= 0 && r + x < m && c + y >= 0 && c + y < n &&
                matrix[r + x][c + y] > matrix[r][c]) {
                dp[r][c] = std::max(dp[r][c], 1 + dfs(matrix, r + x, c + y));
            }
        }

        return dp[r][c];
    }
};
