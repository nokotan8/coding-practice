#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int maximumUniqueSubarray(std::vector<int> &nums) {
        const int n = nums.size();
        std::unordered_map<int, int> freq;
        int dup_count = 0;
        int score = 0;
        int res = 0;
        int r = 0;

        for (int l = 0; l < n; l++) {
            while (r < n && dup_count == 0) {
                res = std::max(res, score);
                score += nums[r];
                freq[nums[r]]++;
                if (freq[nums[r]] > 1) {
                    dup_count++;
                }
                r++;
            }
            if (dup_count == 0) {
                res = std::max(res, score);
            }

            freq[nums[l]]--;
            score -= nums[l];
            if (freq[nums[l]] == 1) {
                dup_count--;
            }
        }

        return res;
    }
};
