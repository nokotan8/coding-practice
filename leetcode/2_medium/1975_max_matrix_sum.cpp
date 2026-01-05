#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>

class Solution {
  public:
    long long maxMatrixSum(std::vector<std::vector<int>> &matrix) {
        long long sum = 0;
        int negative_cnt = 0;
        int min_abs = INT_MAX;

        for (auto &row: matrix) {
            for (auto &e: row) {
                int a = std::abs(e);
                min_abs = std::min(min_abs, a);
                sum += a;
                if (e < 0) {
                    negative_cnt++;
                }
            }
        }

        if (negative_cnt & 1) {
            sum -= min_abs * 2;
        }

        return sum;
    }
};
