#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> res;
    void recurse(std::vector<int> &candidates, int target,
                 std::vector<int> &curr, size_t idx) {
        if (target == 0) {
            res.push_back(curr);
            return;
        } else if (target < 0) {
            return;
        }

        for (size_t i = idx; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            recurse(candidates, target - candidates[i], curr, i);
            curr.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                                 int target) {
        std::vector<int> curr;
        for (size_t i = 0; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            recurse(candidates, target - candidates[i], curr, i);
            curr.pop_back();
        }

        return res;
    }
};
