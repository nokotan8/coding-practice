#include <algorithm>
#include <vector>

class Solution {
  public:
    int maxSubArray(std::vector<int> &nums) {
        const int n = nums.size();
        int res = nums[0];
        int curr = nums[0];

        for (int i = 1; i < n; i++) {
            if (curr > 0) {
                curr += nums[i];
            } else {
                curr = nums[i];
            }

            res = std::max(res, curr);
        }

        return res;
    }
};
