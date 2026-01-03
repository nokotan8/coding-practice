#include <array>
#include <vector>

using namespace std;

class Solution {
    long mod = 1e9 + 7;

  public:
    int numOfWays(int n) {
        vector<array<array<array<int, 3>, 3>, 3>> dp(n);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (i == j || j == k)
                        dp[0][i][j][k] = 0;
                    else
                        dp[0][i][j][k] = 1;
                }
            }
        }

        for (int row = 1; row < n; row++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        if (i == j || j == k) {
                            dp[row][i][j][k] = 0;
                        } else {
                            for (int i_prev = 0; i_prev < 3; i_prev++) {
                                if (i == i_prev) continue;
                                for (int j_prev = 0; j_prev < 3; j_prev++) {
                                    if (j == j_prev) continue;
                                    for (int k_prev = 0; k_prev < 3;
                                         k_prev++) {
                                        if (k == k_prev) continue;

                                        dp[row][i][j][k] = (long)(dp[row][i][j][k] + dp[row - 1][i_prev][j_prev][k_prev]) % mod;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        int res = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    res = (long)(res + dp[n - 1][i][j][k]) % mod;
                }
            }
        }

        return res;
    }
};

// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/solutions/574923/javacpython-dp-o1-space-by-lee215-cr89/?envType=daily-question&envId=2026-01-03
// ^ smart
