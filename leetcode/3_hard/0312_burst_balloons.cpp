#include <algorithm>
#include <climits>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> dp;
    int recurse(std::vector<int> &nums, int lo, int hi) {
        if (lo > hi) {
            return 0;
        } else if (dp[lo][hi] != -1) {
            return dp[lo][hi];
        }

        int res = INT_MIN;
        for (int i = lo; i <= hi; i++) {
            int curr_pop = nums[lo - 1] * nums[i] * nums[hi + 1];
            res = std::max(res, recurse(nums, lo, i - 1) + curr_pop +
                                    recurse(nums, i + 1, hi));
        }

        dp[lo][hi] = res;
        return res;
    }

    int maxCoins(std::vector<int> &nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        const int n = nums.size();
        dp = std::vector<std::vector<int>>(n, std::vector<int>(n, -1));

        return recurse(nums, 1, n - 2);
    }
};
