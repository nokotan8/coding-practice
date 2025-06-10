#include <algorithm>
#include <climits>
#include <string>
class Solution {
  public:
    int maxDifference(std::string s) {
        int freq[26] = {0};
        int max_freq_odd = 0;
        int min_freq_even = INT_MAX;

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0 && (freq[i] & 1) == 0) {
                min_freq_even = std::min(min_freq_even, freq[i]);
            } else if (freq[i] != 0 && (freq[i] & 1) == 1) {
                max_freq_odd = std::max(max_freq_odd, freq[i]);
            }
        }

        return max_freq_odd - min_freq_even;
    }
};
