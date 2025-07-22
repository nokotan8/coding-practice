#include <algorithm>
#include <vector>

class Solution {
  public:
    int maximumLength(std::vector<int> &nums) {
        std::vector<int> maxi(3, 0); // [alternating, odd, even]
        int parity = (nums[0] & 1) ? 0 : 1;
        for (int num : nums) {
            if (num & 1) {
                if (parity == 0) {
                    maxi[0]++;
                }
                maxi[1]++;
            } else {
                if (parity == 1) {
                    maxi[0]++;
                }
                maxi[2]++;
            }

            parity = num & 1;
        }

        return *std::max_element(maxi.begin(), maxi.end());
    }
};
