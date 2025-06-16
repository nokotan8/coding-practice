#include <algorithm>
#include <vector>

#define BUY 1
#define SELL 0

class Solution {
  public:
    int maxProfit(std::vector<int> &prices) {
        const int n = prices.size();
        std::vector<std::vector<int>> dp(n + 2, std::vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            int skip = dp[i + 1][BUY];
            int buy = dp[i + 1][SELL] - prices[i];
            dp[i][BUY] = std::max(skip, buy);

            skip = dp[i + 1][SELL];
            int sell = dp[i + 2][BUY] + prices[i];
            dp[i][SELL] = std::max(skip, sell);
        }

        return dp[0][BUY];
    }
};
