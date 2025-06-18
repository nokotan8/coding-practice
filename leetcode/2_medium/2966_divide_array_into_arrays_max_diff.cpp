#include <algorithm>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> divideArray(std::vector<int> &nums, int k) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }
            res.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }

        return res;
    }
};
