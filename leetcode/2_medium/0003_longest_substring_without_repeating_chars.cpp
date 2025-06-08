#include <algorithm>
#include <string>
#include <unordered_map>
class Solution {
  public:
    int lengthOfLongestSubstring(std::string s) {
        const size_t n = s.size();
        std::unordered_map<char, int> freq;
        size_t l = 0;
        size_t r = 0;
        int max_len = 0;

        while (r != n) {
            freq[s[r]]++;
            while (freq[s[r]] > 1) {
                freq[s[l]]--;
                l++;
            }
            max_len = std::max(max_len, (int)(r - l + 1));
            r++;
        }

        return max_len;
    }
};
