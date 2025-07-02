#include <algorithm>
#include <vector>
class Solution {
  public:
    int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end());

        int res = 0;
        int end = intervals[0][1];
        for (auto it = intervals.begin() + 1; it < intervals.end(); it++) {
            if ((*it)[0] < end) {
                res++;
                end = std::min(end, (*it)[1]);
            } else {
                end = (*it)[1];
            }
        }

        return res;
    }
};
