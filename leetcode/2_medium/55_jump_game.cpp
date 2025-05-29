#include <algorithm>
#include <vector>
class Solution {
  public:
    bool canJump(std::vector<int> &nums) {
        // Maximum reachable index
        int max_i = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (i == nums.size() - 1 ? max_i < i : max_i <= i)
                    return false;
            } else
                max_i = std::max(max_i, i + nums[i]);
        }

        return true;
    }
};
