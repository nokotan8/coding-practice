#include <algorithm>
#include <string>
#include <vector>

class Solution {
    std::vector<std::vector<int>> dp;

  public:
    int edit(std::string &word1, std::string &word2, int idx1, int idx2) {
        if (idx1 == word1.size()) {
            return word2.size() - idx2; // Insert remaining
        } else if (idx2 == word2.size()) {
            return word1.size() - idx1; // Delete remaining
        } else if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }

        if (word1[idx1] == word2[idx2]) {
            dp[idx1][idx2] = edit(word1, word2, idx1 + 1, idx2 + 1);
            return dp[idx1][idx2];
        }

        int res = edit(word1, word2, idx1 + 1, idx2 + 1);        // Replace
        res = std::min(res, edit(word1, word2, idx1 + 1, idx2)); // Delete
        res = std::min(res, edit(word1, word2, idx1, idx2 + 1)); // Insert

        dp[idx1][idx2] = res + 1;
        return dp[idx1][idx2];
    }
    int minDistance(std::string word1, std::string word2) {
        dp = std::vector<std::vector<int>>(word1.size(),
                                           std::vector<int>(word2.size(), -1));

        return edit(word1, word2, 0, 0);
    }
};
