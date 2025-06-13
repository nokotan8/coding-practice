#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int min_buy = INT_MAX;
        int max_profit = 0;

        for (int price : prices) {
            if (price >= min_buy) {
                max_profit = std::max(max_profit, price - min_buy);
            } else {
                min_buy = price;
            }
        }

        return max_profit;
    }
};
