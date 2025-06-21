#include <string>
#include <vector>

class Solution {
    std::vector<std::vector<int>> dp;

  public:
    bool match(std::string &s, std::string &p, int s_idx, int p_idx) {
        if (p_idx == p.size()) {
            return s_idx == s.size();
        } else if (dp[s_idx][p_idx] != -1) {
            return dp[s_idx][p_idx];
        }

        bool curr_match =
            (s_idx < s.size() && (p[p_idx] == '.' || s[s_idx] == p[p_idx]));
        if (p_idx < p.size() - 1 && p[p_idx + 1] == '*') {
            dp[s_idx][p_idx] = match(s, p, s_idx, p_idx + 2);
            if (curr_match) {
                dp[s_idx][p_idx] |= match(s, p, s_idx + 1, p_idx);
            }
        } else {
            dp[s_idx][p_idx] = curr_match && match(s, p, s_idx + 1, p_idx + 1);
        }

        return dp[s_idx][p_idx];
    }

    bool isMatch(std::string s, std::string p) {
        dp = std::vector<std::vector<int>>(s.size() + 1,
                                           std::vector<int>(p.size(), -1));
        return match(s, p, 0, 0);
    }
};
