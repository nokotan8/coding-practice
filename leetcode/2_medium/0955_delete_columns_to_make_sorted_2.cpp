#include <iostream>
#include <string>
#include <vector>

class Solution {
  public:
    int minDeletionSize(std::vector<std::string> &strs) {
        const size_t n = strs[0].size();

        int res = 0;
        size_t prev_idx = -1;
        std::vector<bool> equal(n, true);

        for (size_t i = 0; i < n; i++) {
            bool deleted = false;
            for (size_t j = 1; j < strs.size(); j++) {
                if ((prev_idx != -1 &&
                     strs[j][prev_idx] == strs[j - 1][prev_idx] &&
                     strs[j][i] < strs[j - 1][i]) ||
                    (prev_idx == -1 && strs[j][i] < strs[j - 1][i])) {
                    std::cout << i << '\n';
                    res++;
                    deleted = true;
                    break;
                }
            }
            if (deleted == false) {
                prev_idx = i;
            }
        }

        return res;
    }
};
