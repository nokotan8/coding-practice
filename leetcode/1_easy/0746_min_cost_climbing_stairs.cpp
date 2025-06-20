#include <algorithm>
#include <vector>

class Solution {
  public:
    int minCostClimbingStairs(std::vector<int> &cost) {
        const size_t n = cost.size();
        cost.push_back(0);
        std::vector<int> dp(n + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (size_t i = 2; i <= n; i++) {
            dp[i] = std::min(dp[i - 1], dp[i - 2]) + cost[i];
        }

        return std::min(dp[n - 1], dp[n]);
    }
};
