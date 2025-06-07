/* Space-optimized DP */
#include <string>

class Solution {
  public:
    int numDecodings(std::string s) {
        const size_t n = s.size();
        int prev_2 = 0; // dp[i - 2]
        int prev = 0;   // dp[i - 1]
        int curr = 0;   // dp[i]

        prev_2 = (s[0] != '0');
        if (n == 1)
            return prev_2;

        if (s[1] != '0') {
            prev = prev_2;
        }
        if (s[0] == '1' || (s[0] == '2' && s[1] <= '6')) {
            prev += 1;
        }
        curr = prev;

        for (size_t i = 2; i < n; i++) {
            curr = 0;
            if (s[i] != '0') {
                curr = prev;
            }
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                curr += prev_2;
            }

            prev_2 = prev;
            prev = curr;
        }

        return curr;
    }
};

/* DP */
// #include <string>
// #include <vector>
//
// class Solution {
//   public:
//     int numDecodings(std::string s) {
//         const size_t n = s.size();
//         // dp[i] = # of ways to decode up to and including s[i].
//         std::vector<int> dp(n, 0);
//
//         dp[0] = (s[0] != '0');
//         if (n == 1)
//             return dp[0];
//
//         if (s[1] != '0') {
//             dp[1] = dp[0];
//         }
//         if (s[0] == '1' || (s[0] == '2' && s[1] <= '6')) {
//             dp[1] += 1;
//         }
//
//         for (size_t i = 2; i < n; i++) {
//             if (s[i] != '0') {
//                 dp[i] = dp[i - 1];
//             }
//
//             if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
//                 dp[i] += dp[i - 2];
//             }
//         }
//
//         return dp[n - 1];
//     }
// };
