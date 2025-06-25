#include <climits>
#include <utility>
#include <vector>

class Solution {
  public:
    int findCheapestPrice(int n, std::vector<std::vector<int>> &flights,
                          int src, int dst, int k) {
        std::vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for (int i = 0; i <= k; i++) {
            std::vector<int> tmp = prices;

            for (auto &flight : flights) {
                int s = flight[0];
                int d = flight[1];
                int wt = flight[2];

                if (prices[s] != INT_MAX && prices[s] + wt < tmp[d]) {
                    tmp[d] = prices[s] + wt;
                }
            }
            prices = std::move(tmp);
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
