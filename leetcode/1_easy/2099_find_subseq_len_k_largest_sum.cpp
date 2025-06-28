#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> maxSubsequence(std::vector<int> &nums, int k) {
        std::vector<int> nums_sorted = nums;
        std::unordered_map<int, int> max_nums;
        std::vector<int> res;
        std::sort(nums_sorted.rbegin(), nums_sorted.rend());

        for (int i = 0; i < k; i++) {
            max_nums[nums_sorted[i]]++;
        }

        for (int num : nums) {
            if (max_nums[num] > 0) {
                res.push_back(num);
                max_nums[num]--;
                if (res.size() == k) {
                    break;
                }
            }
        }

        return res;
    }
};
