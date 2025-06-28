#include <algorithm>
#include <vector>

class Solution {
    std::vector<std::vector<int>> res;

  public:
    void recurse(std::vector<int> &nums, int idx, std::vector<int> &curr) {
        if (idx == nums.size()) {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        recurse(nums, idx + 1, curr);
        curr.pop_back();
        if (curr.empty() || curr.back() != nums[idx]) {
            recurse(nums, idx + 1, curr);
        }
    }

    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> curr = {};
        recurse(nums, 0, curr);
        return res;
    }
};
