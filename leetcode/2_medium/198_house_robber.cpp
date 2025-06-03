#include <algorithm>
#include <vector>
class Solution {
  public:
    int rob(std::vector<int> &nums) {
        const size_t n = nums.size();

        // dp[i] = max amount up to house i - 1 inclusive.
        // house i - 1 may or may not be robbed.
        std::vector<int> dp(n + 1, 0);
        dp[1] = nums[0];

        for (size_t i = 2; i <= n; i++) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }

        return dp[n];
    }
};
