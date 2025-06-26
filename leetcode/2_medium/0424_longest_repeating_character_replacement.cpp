#include <algorithm>
#include <string>

class Solution {
  public:
    int characterReplacement(std::string s, int k) {
        int max_len = 0;
        int freq[26] = {0};
        int max_freq = 0;

        int l = 0;
        int r = 0;
        while (r < s.size()) {
            freq[s[r] - 'A']++;
            max_freq = std::max(max_freq, freq[s[r] - 'A']);

            int repl = (r - l + 1) - max_freq;
            if (repl <= k) {
                max_len = std::max(max_len, r - l + 1);
            } else {
                freq[s[l] - 'A']--;
                l++;
            }
            r++;
        }

        return max_len;
    }
};
