#include <string>
#include <vector>

class Solution {
  public:
    bool recurse(std::string &s, std::vector<std::string> &wordDict,
                 std::vector<int> &dp, int idx) {
        if (dp[idx] != -1) {
            return (bool)dp[idx];
        }

        dp[idx] = 0;
        for (auto &word : wordDict) {
            if (idx + word.size() - 1 < s.size() && s.substr(idx, word.size()) == word) {
                dp[idx] |= recurse(s, wordDict, dp, idx + word.size());
                if (dp[idx] == 1) {
                    return true;
                }
            }
        }

        return (bool)dp[idx];
    }

    bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
        std::vector<int> dp(s.size() + 1, -1);
        dp[s.size()] = 1;

        return recurse(s, wordDict, dp, 0);
    }
};
