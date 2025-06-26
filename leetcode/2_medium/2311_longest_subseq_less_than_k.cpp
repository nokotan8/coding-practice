#include <string>

class Solution {
  public:
    int longestSubsequence(std::string s, int k) {
        int curr_len = 0;
        int curr_val = 0;
        int curr_pow = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                curr_len++;
                if (curr_pow <= k) {
                    curr_pow *= 2;
                }
            } else if (curr_len <= 29 && curr_val + curr_pow <= k) {
                // k <= 10^9, so 2^x <= 10^9, x <= 29
                curr_val += curr_pow;
                curr_len++;
                curr_pow *= 2;
            }
        }

        return curr_len;
    }
};
