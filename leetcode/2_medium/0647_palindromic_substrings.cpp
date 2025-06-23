#include <string>

class Solution {
  public:
    int countSubstrings(std::string s) {
        int res = 1;
        int n = s.size();

        for (int i = 0; i < n - 1; i++) {
            res++;
            int l = i - 1;
            int r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }
        }

        return res;
    }
};
