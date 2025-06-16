#include <string>

class Solution {
  public:
    bool isPalindrome(std::string s) {
        const int n = (int)s.size();
        int l = 0;
        int r = n - 1;

        while (l < r) {
            while (l < n && !((s[l] >= '0' && s[l] <= '9') ||
                              (s[l] >= 'A' && s[l] <= 'Z') ||
                              s[l] >= 'a' && s[l] <= 'z')) {
                l++;
            }
            while (r >= 0 && !((s[r] >= '0' && s[r] <= '9') ||
                               (s[r] >= 'A' && s[r] <= 'Z') ||
                               s[r] >= 'a' && s[r] <= 'z')) {
                r--;
            }

            if (l >= r)
                break;

            if (s[l] >= 'A' && s[l] < 'a') {
                s[l] += 32;
            }
            if (s[r] >= 'A' && s[r] < 'a') {
                s[r] += 32;
            }

            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }
};
