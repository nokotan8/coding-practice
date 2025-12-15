#include <vector>

class Solution {
  public:
    long long zeroFilledSubarray(std::vector<int> &nums) {
        long long res = 0;
        int prev = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                res += ++prev;
            } else {
                prev = 0;
            }
        }

        return res;
    }
};
