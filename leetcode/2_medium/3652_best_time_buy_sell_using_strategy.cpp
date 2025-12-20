#include <algorithm>
#include <vector>

class Solution {
  public:
    long long maxProfit(std::vector<int> &prices, std::vector<int> &strategy,
                        int k) {
        size_t n = strategy.size();

        long long profit = 0;
        long long max_profit = 0;
        for (size_t i = 0; i < n; i++) {
            profit += prices[i] * strategy[i];
        }
        max_profit = profit;

        for (int i = 0; i < k / 2; i++) {
            profit -= prices[i] * strategy[i];
        }
        for (int i = k / 2; i < k; i++) {
            profit -= prices[i] * (strategy[i] - 1);
        }
        max_profit = std::max(max_profit, profit);

        for (int i = 1; i <= n - k; i++) {
            int j = i - 1;
            // revert first
            profit += prices[j] * strategy[j];

            // change middle from 1 -> 0
            profit -= prices[i + k / 2 - 1];

            // add 1 on end
            j = i + k - 1;
            profit -= prices[j] * (strategy[j] - 1);

            max_profit = std::max(max_profit, profit);
        }

        return max_profit;
    }
};
