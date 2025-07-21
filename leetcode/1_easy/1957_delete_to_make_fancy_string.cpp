#include <string>

class Solution {
  public:
    std::string makeFancyString(std::string s) {
        if (s.size() < 3) {
            return s;
        }

        int idx = 2;
        for (int i = 2; i < s.size(); i++) {
            if (s[i] != s[idx - 1] || s[i] != s[idx - 2]) {
                s[idx++] = s[i];
            }
        }

        return s.substr(0, idx);
    }
};
