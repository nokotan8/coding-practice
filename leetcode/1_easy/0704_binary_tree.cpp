#include <vector>
class Solution {
  public:
    int search(std::vector<int> &nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo <= hi) {
            int md = (lo + hi) / 2;
            if (nums[md] == target) {
                return md;
            }

            if (target < nums[md]) {
                hi = md - 1;
            } else {
                lo = md + 1;
            }
        }

        return -1;
    }
};
