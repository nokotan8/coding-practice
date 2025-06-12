#include <algorithm>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        const size_t n = nums.size();
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());

        for (size_t i = 0; i < n - 2; i++) {
            int target = -nums[i];
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                } else if (nums[l] + nums[r] < target) {
                    l++;
                } else if (nums[l] + nums[r] > target) {
                    r--;
                }
            }

            while (i < n - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
        }

        return res;
    }
};
