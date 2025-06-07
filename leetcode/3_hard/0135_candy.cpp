#include <algorithm>
#include <numeric>
#include <vector>
class Solution {
  public:
    int candy(std::vector<int> &ratings) {
        const size_t n = ratings.size();
        std::vector<int> candies(n, 1);

        for (size_t i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (size_t i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }

        return std::accumulate(candies.begin(), candies.end(), 0);
    }
};
