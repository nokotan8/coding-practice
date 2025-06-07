// https://leetcode.com/problems/continuous-subarray-sum
// this soln is horrible
#include <unordered_map>
#include <vector>

class Solution {
  public:
    bool checkSubarraySum(std::vector<int> &nums, int k) {
        std::vector<int> pSumMod(nums.size());
        std::unordered_map<int, int> index;

        pSumMod[0] = nums[0] % k;
        index[pSumMod[0]] = 0;
        for (int i = 1; i < nums.size(); i++) {
            pSumMod[i] = (nums[i] + pSumMod[i - 1]) % k;
            if (!pSumMod[i]) {
                return true;
            } else if (index.find(pSumMod[i]) != index.end()) {
                if (i - index[pSumMod[i]] > 1) {
                    return true;
                }
            } else {
                index[pSumMod[i]] = i;
            }
        }

        return false;
    }
};
