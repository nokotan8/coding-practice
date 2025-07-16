#include <string>
#include <unordered_map>
#include <utility>

class Solution {
  public:
    std::string minWindow(std::string s, std::string t) {
        std::unordered_map<char, int> freq_s;
        std::unordered_map<char, int> freq_t;
        for (char c : t) {
            freq_t[c]++;
        }

        std::pair<int, int> min_window = {-1, s.size() + 1};
        int l = 0;
        int r = 0;

        int have = 0;
        const int need = t.size();

        while (r < s.size() + 1) {
            while (r < s.size() && have < need) {
                if (freq_s[s[r]] < freq_t[s[r]]) {
                    have++;
                }
                freq_s[s[r]]++;
                r++;
            }
            while (l < s.size() && freq_s[s[l]] > freq_t[s[l]]) {
                freq_s[s[l]]--;
                l++;
            }

            if (have == need && r - l < min_window.second - min_window.first) {
                min_window = {l, r};
            }

            if (l < s.size()) {
                if (freq_s[s[l]] <= freq_t[s[l]]) {
                    have--;
                }
                freq_s[s[l]]--;
                l++;
            } else {
                break;
            }
        }

        return min_window.first == -1
                   ? ""
                   : s.substr(min_window.first,
                              min_window.second - min_window.first);
    }
};
