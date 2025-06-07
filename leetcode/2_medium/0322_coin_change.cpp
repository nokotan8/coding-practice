#include <algorithm>
#include <climits>
#include <vector>

class Solution {
  public:
    int calc(std::vector<int> &coins, int amount, std::vector<int> &dp) {
        if (dp[amount] != -1)
            return dp[amount];

        int res = INT_MAX;
        for (size_t i = 0; i < coins.size(); i++) {
            if (amount >= coins[i]) {
                int num = calc(coins, amount - coins[i], dp);
                if (num != INT_MAX)
                    res = std::min(res, num + 1);
            }
        }

        dp[amount] = res;
        return dp[amount];
    }

    int coinChange(std::vector<int> &coins, int amount) {
        std::vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        int res = calc(coins, amount, dp);

        return res == INT_MAX ? -1 : res;
    }
};
