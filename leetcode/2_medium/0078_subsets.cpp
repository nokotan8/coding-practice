#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
        std::vector<std::vector<int>> res;
        const size_t n = nums.size();
        const int max_mask = 1 << n;

        for (int i = 0; i < max_mask; i++) {
            std::vector<int> curr;
            for (int j = 0, mask = 1; j < nums.size(); j++, mask <<= 1) {
                if (i & mask) {
                    curr.push_back(nums[j]);
                }
            }
            res.push_back(curr);
        }

        return res;
    }
};
