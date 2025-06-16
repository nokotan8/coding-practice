#include <algorithm>
#include <climits>
#include <vector>

class Solution {
  public:
    int maximumDifference(std::vector<int> &nums) {
        const size_t n = nums.size();
        int curr_min = nums[0];

        int max_diff = -1;
        for (size_t i = 1; i < n; i++) {
            if (nums[i] > curr_min) {
                max_diff = std::max(max_diff, nums[i] - curr_min);
            } else {
                curr_min = nums[i];
            }
        }

        return max_diff;
    }
};
