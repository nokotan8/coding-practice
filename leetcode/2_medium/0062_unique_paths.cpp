// #include <vector>
//
// class Solution {
//   private:
//     std::vector<std::vector<int>> dp;
//
//     int recurse(int i, int j, int m, int n) {
//         if (i == m - 1 && j == n - 1) {
//             return 1;
//         } else if (dp[i][j]) {
//             return dp[i][j];
//         }
//         int res = 0;
//         if (i < m - 1) {
//             res += recurse(i + 1, j, m, n);
//         }
//         if (j < n - 1) {
//             res += recurse(i, j + 1, m, n);
//         }
//
//         dp[i][j] = res;
//         return res;
//     }
//
//   public:
//     int uniquePaths(int m, int n) {
//         dp = std::vector<std::vector<int>>(m, std::vector<int>(n));
//         return recurse(0, 0, m, n);
//     }
// };

#include <cstring>
#include <vector>

class Solution {
  public:
    int uniquePaths(int m, int n) {
        std::vector<int> prev_row;
        std::vector<int> curr_row(n);
        curr_row[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    curr_row[j] += prev_row[j];
                }
                if (j > 0) {
                    curr_row[j] += curr_row[j - 1];
                }
            }

            prev_row = curr_row;
            memset(curr_row.data(), 0, curr_row.size() * sizeof(int));
        }

        return prev_row[n - 1];
    }
};
