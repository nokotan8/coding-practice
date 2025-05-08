#include <algorithm>
#include <unordered_map>
#include <vector>
class Solution {
  public:
    int maxSubarrayLength(std::vector<int> &nums, int k) {
        int maxLen = 0;
        std::unordered_map<int, int> freq;
        int l = 0;
        int r = 0;
        freq[nums[0]] = 1;
        while (r < nums.size() - 1) {
            maxLen = std::max(maxLen, r - l + 1);
            freq[nums[++r]]++;
            while (freq[nums[r]] > k) {
                freq[nums[l++]]--;
            }
        }
        maxLen = std::max(maxLen, r - l + 1);

        return maxLen;
    }
};
