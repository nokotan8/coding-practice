#include <algorithm>
#include <climits>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int maxSum(std::vector<int> &nums) {
        std::unordered_set<int> e;
        int max_e = INT_MIN;
        int sum = 0;

        for (int num : nums) {
            max_e = std::max(max_e, num);
            if (num > 0 && e.count(num) == 0) {
                sum += num;
                e.insert(num);
            }
        }

        return max_e < 0 ? max_e : sum;
    }
};
