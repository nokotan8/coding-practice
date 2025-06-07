#include <vector>
class Solution {
  public:
    void setZeroes(std::vector<std::vector<int>> &matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool zero_in_first_col = false;

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0)
                zero_in_first_col = true;
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (zero_in_first_col)
                matrix[i][0] = 0;
        }
    }
};
