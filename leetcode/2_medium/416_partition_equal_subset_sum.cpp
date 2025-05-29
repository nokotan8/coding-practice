/* Optimization with bitset */
#include <bitset>
#include <numeric>
#include <vector>
class Solution {
  public:
    bool canPartition(std::vector<int> &nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        int target = sum / 2;
        // Max sum = 20000 -> max target = 10000,
        // hence bitset of size 10001
        std::bitset<10001> dp;
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            dp |= (dp << nums[i]);
            if (dp[target])
                return true;
        }

        return dp[target];
    }
};

/* 0/1 Knapsack */
// #include <numeric>
// #include <vector>
// class Solution {
//   public:
//     bool canPartition(std::vector<int> &nums) {
//         int sum = std::accumulate(nums.begin(), nums.end(), 0);
//         if (sum % 2)
//             return false;
//         int target = sum / 2;
//         std::vector<bool> dp(target + 1, false);
//         dp[0] = true;
//
//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = target; j >= nums[i]; j--) {
//                 if (dp[j - nums[i]])
//                     dp[j] = true;
//             }
//             if (dp[target])
//                 return true;
//         }
//
//         return dp[target];
//     }
// };
