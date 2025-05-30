/* Greedy */
#include <vector>
class Solution {
  public:
    int jump(std::vector<int> &nums) {
        const size_t n = nums.size();
        int count = 0;
        if (n == 1)
            return count;
        size_t pos = 0;

        while (1) {
            count++;
            size_t max_i = pos + nums[pos];
            size_t jump_i = pos;
            if (max_i >= n - 1)
                break;
            for (int i = pos + 1; i <= pos + nums[pos]; i++) {
                if (i + nums[i] > max_i) {
                    jump_i = i;
                    max_i = i + nums[i];
                }
            }
            pos = jump_i;
        }

        return count;
    }
};

/* DP */
// #include <algorithm>
// #include <climits>
// #include <vector>
// class Solution {
//   public:
//     int jump(std::vector<int> &nums) {
//         const size_t n = nums.size();
//         std::vector<int> dp(n, INT_MAX);
//         dp[n - 1] = 0;
//         for (int i = n - 2; i >= 0; i--) {
//             for (size_t j = i + 1; j < n && j <= i + nums[i]; j++)
//                 if (dp[j] < INT_MAX)
//                     dp[i] = std::min(dp[i], dp[j] + 1);
//         }
//
//         return dp[0];
//     }
// };
