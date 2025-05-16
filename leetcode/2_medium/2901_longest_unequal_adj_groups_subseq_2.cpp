#include <string>
#include <vector>

class Solution {
  public:
    // Assumes w1.size() == w2.size()
    static int hammingDistance(std::string &w1, std::string &w2) {
        int count = 0;
        for (int i = 0; i < w1.size(); i++) {
            if (w1[i] != w2[i])
                count++;
        }

        return count;
    }
    std::vector<std::string>
    getWordsInLongestSubsequence(std::vector<std::string> &words,
                                 std::vector<int> &groups) {
        const int n = words.size();
        // dp[i] = length of longest subseq ending at words[i]
        // prev[i] = previous index j where words[i] and words[j]
        // meet the conditions
        std::vector<int> dp(n, 0);
        std::vector<int> prev_index(n, -1);

        dp[0] = 1;
        int max_index = 0;
        int max_len = 1;

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (words[i].size() == words[j].size() &&
                    groups[i] != groups[j] &&
                    hammingDistance(words[i], words[j]) == 1) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev_index[i] = j;
                    }
                }
            }

            if (!dp[i])
                dp[i] = 1;
            else if (dp[i] > max_len) {
                max_index = i;
                max_len = dp[i];
            }
        }

        std::vector<std::string> res(max_len, "");
        int curr_index = max_index;
        int curr_res_index = max_len - 1;
        while (curr_index > -1) {
            res[curr_res_index--] = words[curr_index];
            curr_index = prev_index[curr_index];
        }

        return res;
    }
};
