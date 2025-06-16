#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>

class Solution {
public:
    int maxAdjacentDistance(std::vector<int>& nums) {
        int diff = INT_MIN;

        for (size_t i = 0; i < nums.size() - 1; i++) {
            diff = std::max(diff, abs(nums[i + 1] - nums[i]));
        }

        diff = std::max(diff, abs(nums.back() - nums.front()));

        return diff;
    }
};
