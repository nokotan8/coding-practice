#include <algorithm>
#include <vector>

class Solution {
public:
    int partitionArray(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int partitions = 1;
        int curr_min = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] - curr_min > k) {
                curr_min = nums[i];
                partitions++;
            }
        }

        return partitions;
    }
};
