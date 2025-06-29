#include <algorithm>
#include <vector>

class Solution {
  public:
    int modu = 1e9 + 7;
    int numSubseq(std::vector<int> &nums, int target) {
        int res = 0;
        std::vector<int> pows = {1};
        for (int i = 0; i < nums.size() - 1; i++) {
            pows.push_back((pows.back() << 1) % modu);
        }

        std::sort(nums.begin(), nums.end());

        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r--;
            } else {
                res = (res + pows[r - l]) % modu;
                l++;
            }
        }

        return res;
    }
};
