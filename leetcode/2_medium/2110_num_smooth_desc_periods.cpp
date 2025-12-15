#include <vector>

class Solution {
  public:
    long long getDescentPeriods(std::vector<int> &prices) {
        if (prices.size() == 1) {
            return 1;
        }

        long long res = 0;
        size_t count = 1;

        for (size_t i = 1; i < prices.size(); i++) {
            if (prices[i - 1] - 1 == prices[i]) {
                count++;
            } else {
                res += (count * (count + 1)) / 2;
                count = 1;
            }
        }
        res += (count * (count + 1)) / 2;

        return res;
    }
};
