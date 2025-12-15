#include <algorithm>
#include <string>
#include <vector>

class Solution {
  public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        size_t m = text1.size();
        size_t n = text2.size();

        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        return dp[m][n];
    }
};
