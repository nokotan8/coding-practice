#include <algorithm>
#include <climits>
#include <vector>

class Solution {
  public:
    int maxProduct(std::vector<int> &nums) {
        int max = INT_MIN;
        int prod = 1;

        for (int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            max = std::max(prod, max);
            if (!prod) {
                prod = 1;
            }
        }
        prod = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            prod *= nums[i];
            max = std::max(prod, max);
            if (!prod) {
                prod = 1;
            }
        }

        return max;
    }
};
