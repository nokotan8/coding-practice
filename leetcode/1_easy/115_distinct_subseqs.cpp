#include <string>
#include <vector>
class Solution {
  public:
    int solve(std::string &s, std::string &t, int s_idx, int t_idx,
              std::vector<std::vector<int>> &dp) {
        if (t_idx == t.size())
            return 1;
        else if (s_idx == s.size())
            return 0;
        else if (dp[s_idx][t_idx] != -1)
            return dp[s_idx][t_idx];

        int res = 0;

        if (s[s_idx] == t[t_idx]) {
            res += solve(s, t, s_idx + 1, t_idx + 1, dp);
        }
        res += solve(s, t, s_idx + 1, t_idx, dp);

        return dp[s_idx][t_idx] = res;
    }
    int numDistinct(std::string s, std::string t) {
        if (t.size() > s.size())
            return 0;

        // dp[i][j] = number of substrings t[j:] in s[i:] (I think?)
        std::vector<std::vector<int>> dp(s.size(),
                                         std::vector<int>(t.size(), -1));
        return solve(s, t, 0, 0, dp);
    }
};
