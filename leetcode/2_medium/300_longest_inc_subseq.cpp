#include <algorithm>
#include <vector>
class Solution {
  public:
    int lengthOfLIS(std::vector<int> &nums) {
        std::vector<int> subseq;
        subseq.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > subseq.back())
                subseq.push_back(nums[i]);
            else {
                *std::lower_bound(subseq.begin(), subseq.end(), nums[i]) =
                    nums[i];
            }
        }

        return subseq.size();
    }
};
