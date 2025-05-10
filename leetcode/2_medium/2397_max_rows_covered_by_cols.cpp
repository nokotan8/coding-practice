#include <algorithm>
#include <vector>
class Solution {
  public:
    int maximumRows(std::vector<std::vector<int>> &matrix, int numSelect) {
        int maxRows = 0;
        int max = (1 << matrix[0].size()) - 1;
        for (int mask = 1; mask <= max; mask++) {
            if (__builtin_popcount(mask) != numSelect)
                continue;
            int count = 0;
            for (auto &row : matrix) {
                bool covered = true;
                for (int i = 0; i < row.size(); i++) {
                    if (row[i] && (mask & (1 << i)) == 0) {
                        covered = false;
                        break;
                    }
                }
                if (covered) {
                    count++;
                }
            }
            maxRows = std::max(maxRows, count);
        }

        return maxRows;
    }
};
