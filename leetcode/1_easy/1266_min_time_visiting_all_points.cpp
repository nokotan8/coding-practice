#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points) {
        int res = 0;
        for (int i = 1; i < points.size(); i++) {
            int x_diff = abs(points[i][0] - points[i - 1][0]);
            int y_diff = abs(points[i][1] - points[i - 1][1]);

            res += max(x_diff, y_diff);
        }

        return res;
    }
};
