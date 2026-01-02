#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res(n, 1);
        
        for (int i = 0; i < n - 1; i++) {
            res[i + 1] = res[i] * nums[i];
        }

        int prod = 1;
        for (int i = n - 1; i > 0; i--) {
            prod *= nums[i];
            res[i - 1] *= prod;
        }

        return res;
    }
};
