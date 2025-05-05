#include <vector>
class Solution {
  public:
    std::vector<int> minBitwiseArray(std::vector<int> &nums) {
        std::vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                ans[i] = -1;
            } else {
                int mask = 1;
                while ((mask & nums[i]) == mask) {
                    mask <<= 1;
                }
                ans[i] = nums[i] ^ (mask >> 1);
            }
        }

        return ans;
    }
};
