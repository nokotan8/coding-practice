#include <string>

class Solution {
  public:
    std::string longestPalindrome(std::string s) {
        const int n = s.size();

        int res_idx = 0;
        int res_len = 1;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < 2; j++) {
                int l = i;
                int r = i + j;
                while (l >= 0 && r < n && s[l] == s[r]) {
                    l--;
                    r++;
                }
                int curr_len = r - l - 1;
                if (curr_len > res_len) {
                    res_len = curr_len;
                    res_idx = l + 1;
                }
            }
        }

        return s.substr(res_idx, res_len);
    }
};
