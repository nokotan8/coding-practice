#include <vector>

class Solution {
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            if (target == nums[l] + nums[r]) {
                break;
            } else if (target < nums[l] + nums[r]) {
                r--;
            } else {
                l++;
            }
        }

        return {l + 1, r + 1};
    }
};
