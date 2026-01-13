#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    inline double area_below(vector<vector<int>> &squares, double y) {
        double res = 0;
        for (auto &s : squares) {
            if (s[1] < y) {
                res += s[2] * min((double)s[2], y - s[1]);
            }
        }
        return res;
    }

public:
    double separateSquares(vector<vector<int>> &squares) {
        double total_area = 0;
        double lo = 0, hi = 0;

        for (auto &s : squares) {
            total_area += (double)s[2] * s[2];
            hi = max(hi, (double)s[1] + s[2]);
        }

        double target_area = total_area / 2;
        while (hi - lo > 1e-5) {
            double mid = lo + (hi - lo) / 2;
            if (area_below(squares, mid) >= target_area) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return lo;
    }
};
