#include <algorithm>
#include <vector>

class Solution {
  public:
    int rob(std::vector<int> &nums) {
        const size_t n = nums.size();
        if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return std::max(nums[0], nums[1]);
        }

        std::vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (size_t i = 2; i < n - 1; i++) {
            dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        int max1 = *std::max_element(dp.begin(), dp.end());

        dp[0] = 0;
        dp[1] = nums[1];
        dp[2] = std::max(nums[1], nums[2]);
        for (size_t i = 3; i < n; i++) {
            dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        int max2 = *std::max_element(dp.begin(), dp.end());

        return std::max(max1, max2);
    }
};
