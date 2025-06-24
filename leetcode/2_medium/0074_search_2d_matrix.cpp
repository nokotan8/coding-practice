#include <vector>

class Solution {
  public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        int lo = 0;
        int hi = m * n - 1;

        while (lo <= hi) {
            int md = (lo + hi) / 2;

            int x = md / n;
            int y = md % n;
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] < target) {
                lo = md + 1;
            } else {
                hi = md - 1;
            }
        }

        return false;
    }
};
