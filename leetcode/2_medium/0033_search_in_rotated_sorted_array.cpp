#include <vector>

class Solution {
  public:
    int search(std::vector<int> &nums, int target) {
        const size_t n = nums.size();
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }

        int lo = 0;
        int hi = (int)n - 1;
        while (lo <= hi) {
            int md = (lo + hi) / 2;
            if (nums[md] == target) {
                return md;
            }

            if (nums[lo] <= nums[md]) {
                if (nums[md] > target && target >= nums[lo]) {
                    hi = md - 1;
                } else {
                    lo = md + 1;
                }
            } else {
                if (nums[md] < target && target <= nums[hi]) {
                    lo = md + 1;
                } else {
                    hi = md - 1;
                }
            }
        }

        return -1;
    }
};
