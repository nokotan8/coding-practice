#include <unordered_set>
#include <vector>
class Solution {
  public:
    std::vector<std::vector<int>> res;

    void solve(std::vector<int> &nums, std::vector<int> &curr,
               std::unordered_set<int> &used, int i) {
        if (i == nums.size()) {
            res.push_back(curr);
            return;
        }

        for (int num : nums) {
            if (used.count(num) == 0) {
                curr[i] = num;
                used.insert(num);
                solve(nums, curr, used, i + 1);
                used.erase(num);
            }
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int> &nums) {

        std::vector<int> curr(nums.size());
        std::unordered_set<int> used;
        solve(nums, curr, used, 0);

        return res;
    }
};
