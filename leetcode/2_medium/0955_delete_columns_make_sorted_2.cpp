#include <string>
#include <vector>

class Solution {
  public:
    int minDeletionSize(std::vector<std::string> &strs) {
        int n = strs.size();
        int m = strs[0].size();
        int count = 0;

        std::vector<bool> sorted(n, false);

        for (int j = 0; j < m; j++) {
            int i = 0;
            for (; i < n - 1; i++) {
                if (sorted[i] == false && strs[i][j] > strs[i + 1][j]) {
                    count++;
                    break;
                }
            }
            if (i == n - 1) {
                for (int k = 0; k < n - 1; k++) {
                    if (sorted[k] || strs[k][j] < strs[k + 1][j]) {
                        sorted[k] = true;
                    }
                }
            }
        }

        return count;
    }
};
