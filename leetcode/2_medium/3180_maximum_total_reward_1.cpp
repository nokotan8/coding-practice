#include <algorithm>
#include <vector>
class Solution {
  public:
    int maxTotalReward(std::vector<int> &rewardValues) {
        const int n = rewardValues.size();
        std::sort(rewardValues.begin(), rewardValues.end());
        std::vector<std::vector<bool>> dp(
            n + 1, std::vector<bool>(rewardValues[n - 1] * 2, false));

        dp[0][0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                if (dp[i][j]) {
                    dp[i + 1][j] = true;
                } else if (j - rewardValues[i] >= 0 &&
                           rewardValues[i] > j - rewardValues[i]) {
                    dp[i + 1][j] = dp[i][j - rewardValues[i]];
                }
            }
        }

        // for (auto &x : dp) {
        //     for (auto y : x) {
        //         std::cout << y << ' ';
        //     }
        //     std::cout << '\n';
        // }

        for (int i = dp[n].size() - 1; i >= 0; i--) {
            if (dp[n][i]) {
                return i;
            }
        }

        return 0;
    }
};
