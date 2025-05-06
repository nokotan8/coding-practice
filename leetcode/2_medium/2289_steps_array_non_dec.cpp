#include <algorithm>
#include <stack>
#include <vector>
class Solution {
  public:
    int totalSteps(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> dp(nums.size(), 0);
        std::stack<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() && nums[i] > nums[stk.top()]) {
                dp[i] = std::max(dp[i] + 1, dp[stk.top()]);
                stk.pop();
            }
            stk.push(i);
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};
