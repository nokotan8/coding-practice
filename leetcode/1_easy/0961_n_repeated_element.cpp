#include <vector>

class Solution {
public:
    int repeatedNTimes(std::vector<int>& nums) {
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] || nums[i] == nums[i - 2]) {
                return nums[i];
            }
        }
        return nums[0];
    }
};
