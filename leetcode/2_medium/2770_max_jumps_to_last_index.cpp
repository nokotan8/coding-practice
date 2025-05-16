#include <vector>
class Solution {
  public:
    int maximumJumps(std::vector<int> &nums, int target) {
        const int n = nums.size();
        // dp[i] = max # of jumps to get from i -> n - 1
        std::vector<int> dp(n, -1);
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (dp[j] != -1 && dp[j] + 1 > dp[i] &&
                    nums[j] - nums[i] >= -target &&
                    nums[j] - nums[i] <= target) {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        return dp[0];
    }
};
