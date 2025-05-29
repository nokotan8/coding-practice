#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>
class Solution {
  public:
    long long maximumValueSum(std::vector<int> &nums, int k,
                              std::vector<std::vector<int>> &edges) {
        long long total = 0;
        int xor_count = 0;
        int min_loss = INT_MAX;

        for (int num : nums) {
            int num_xor = num ^ k;
            total += std::max(num, num_xor);
            xor_count += num_xor > num ? 1 : 0;
            min_loss = std::min(min_loss, abs(num_xor - num));
        }

        return xor_count % 2 == 0 ? total : total - min_loss;
    }
};

/* O(n) DP */
// #include <climits>
// #include <vector>
// class Solution {
//   public:
//     long long maximumValueSum(std::vector<int> &nums, int k,
//                               std::vector<std::vector<int>> &edges) {
//         std::vector<std::vector<long long>> dp(nums.size(),
//                                                std::vector<long long>(2, -1));
//
//         return maxSum(0, 1, nums, k, dp);
//     }
//
//     long long maxSum(int index, int ops_even, std::vector<int> &nums, int k,
//                      std::vector<std::vector<long long>> &dp) {
//         if (index == nums.size()) {
//             return ops_even ? 0 : INT_MIN;
//         }
//
//         if (dp[index][ops_even] != -1)
//             return dp[index][ops_even];
//
//         long long flip = (nums[index] ^ k) +
//                          maxSum(index + 1, ops_even ? 0 : 1, nums, k, dp);
//
//         long long noflip =
//             nums[index] + maxSum(index + 1, ops_even, nums, k, dp);
//
//         dp[index][ops_even] = std::max(flip, noflip);
//
//         return dp[index][ops_even];
//     }
// };

/* O(nlogn) Greedy
Faster than DP, however */
// #include <algorithm>
// #include <vector>
// class Solution {
//   public:
//     long long maximumValueSum(std::vector<int> &nums, int k,
//                               std::vector<std::vector<int>> &edges) {
//         const int n = nums.size();
//         long long res = 0;
//         std::vector<int> delta(n);
//         for (int i = 0; i < n; i++) {
//             delta[i] = (nums[i] ^ k) - nums[i];
//             res += nums[i];
//         }
//
//         std::sort(delta.begin(), delta.end(), std::greater<int>());
//
//         for (int j = 0; j < n; j += 2) {
//             if (j == n - 1)
//                 break;
//
//             res += std::max(delta[j] + delta[j + 1], 0);
//         }
//
//         return res;
//     }
// };
