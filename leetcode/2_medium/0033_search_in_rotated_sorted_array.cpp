#include <vector>

class Solution {
  public:
    int search(std::vector<int> &nums, int target) {
        const size_t n = nums.size();
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }

        size_t start;
        for (size_t i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                start = i;
                break;
            }
        }

        int lo = 0;
        int hi = (int)n - 1;
        while (lo <= hi) {
            int md = (lo + hi) / 2;
            int real_md = (md + start) % n;

            if (nums[real_md] == target) {
                return real_md;
            } else if (nums[real_md] > target) {
                hi = md - 1;
            } else {
                lo = md + 1;
            }
        }

        return -1;
    }
};
