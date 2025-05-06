#include <vector>
class Solution {
  public:
    std::vector<int> buildArray(std::vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            int ans = nums[nums[i]] % 1000;
            nums[i] = nums[i] + 1000 * ans;
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] / 1000;
        }

        return nums;
    }
};
