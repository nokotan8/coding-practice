#include <algorithm>
#include <vector>

class Solution {
  private:
    std::vector<std::vector<int>> dp;

    int recurse(std::vector<int> &coins, int target, int idx) {
        if (target == 0) {
            return 1;
        } else if (idx == coins.size()) {
            return 0;
        } else if (dp[target][idx] != -1) {
            return dp[target][idx];
        }

        int res = 0;
        if (target >= coins[idx]) {
            res += recurse(coins, target - coins[idx], idx);
            res += recurse(coins, target, idx + 1);
        }

        dp[target][idx] = res;
        return res;
    }

  public:
    int change(int amount, std::vector<int> &coins) {
        if (amount == 0) {
            return 1;
        }

        std::sort(coins.begin(), coins.end());
        dp = std::vector<std::vector<int>>(amount + 1,
                                           std::vector<int>(coins.size(), -1));
        return recurse(coins, amount, 0);
    }
};
