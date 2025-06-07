/* Space-optimized bottom-up DP */
#include <cstdlib>
#include <unordered_map>
#include <utility>
#include <vector>
class Solution {
  public:
    int findTargetSumWays(std::vector<int> &nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if ((target + sum) % 2 != 0 || std::abs(target) > sum) {
            return 0;
        }

        // dp[i] = # of ways to sum to i
        std::unordered_map<int, int> dp;
        dp[0] = 1;

        for (int num : nums) {
            std::unordered_map<int, int> dp_curr;
            for (auto &[sum, ways] : dp) {
                dp_curr[sum + num] += ways;
                dp_curr[sum - num] += ways;
            }

            dp = std::move(dp_curr);
        }

        return dp[target];
    }
};

/* Slower bottom-up DP */
// #include <numeric>
// #include <unordered_map>
// #include <vector>
// class Solution {
//   public:
//     int solve(std::vector<int> &nums, int index, int curr_sum,
//               std::vector<std::unordered_map<int, int>> &dp, int &target) {
//         if (index == nums.size())
//             return curr_sum == target ? 1 : 0;
//         if (dp[index].find(curr_sum) != dp[index].end())
//             return dp[index][curr_sum];
//
//         int add = solve(nums, index + 1, curr_sum + nums[index], dp, target);
//         int subt = solve(nums, index + 1, curr_sum - nums[index], dp, target);
//
//         return dp[index][curr_sum] = add + subt;
//     }
//     int findTargetSumWays(std::vector<int> &nums, int target) {
//         int sum = std::accumulate(begin(nums), end(nums), 0);
//         std::vector<std::unordered_map<int, int>> dp(nums.size());
//
//         return solve(nums, 0, 0, dp, target);
//     }
// };
