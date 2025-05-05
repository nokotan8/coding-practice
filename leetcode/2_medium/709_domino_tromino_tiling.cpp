#include <algorithm>
#include <cmath>
#include <vector>
class Solution {
  public:
    int numTilings(int n) {
        const int nmod = pow(10, 9) + 7;
        std::vector<long long> dp(std::max(n, 2) + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % nmod;
        }

        return dp[n];
    }
};
