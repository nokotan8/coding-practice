#include <vector>

class Solution {
  public:
    int findMin(std::vector<int> &nums) {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo < hi) {
            int md = (lo + hi) / 2;
            if (nums[md] < nums[hi]) {
                hi = md;
            } else {
                lo = md + 1;
            }
        }

        return nums[lo];
    }
};
