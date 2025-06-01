#include <algorithm>
class Solution {
  public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        for (int i = 0; i <= std::min(n, limit); i++) {
            res += std::max(
                std::min(limit, n - i) - std::max(0, n - i - limit) + 1, 0);
        }

        return res;
    }
};
