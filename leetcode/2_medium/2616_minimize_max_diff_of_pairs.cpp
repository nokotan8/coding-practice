#include <algorithm>
#include <cstdlib>
#include <vector>

class Solution {
  public:
    bool valid_diff(std::vector<int> &nums, int p, int diff) {
        int pairs = 0;
        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] - nums[i] <= diff) {
                pairs++;
                i++;
            }
        }

        return pairs >= p;
    }

    int minimizeMax(std::vector<int> &nums, int p) {
        std::sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.back() - nums.front();

        while (l < r) {
            int md = (l + r) / 2;
            if (valid_diff(nums, p, md)) {
                r = md;
            } else {
                l = md + 1;
            }
        }

        return l;
    }
};
