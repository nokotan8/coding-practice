#include <algorithm>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>>
    merge(std::vector<std::vector<int>> &intervals) {
        std::vector<std::vector<int>> res;

        std::sort(intervals.begin(), intervals.end());
        int start = -1;
        int end = -1;
        for (size_t i = 0; i < intervals.size(); i++) {
            if (start == -1 || end == -1) {
                start = intervals[i][0];
                end = intervals[i][1];
            }

            while (i < intervals.size() && intervals[i][0] <= end) {
                end = std::max(end, intervals[i][1]);
                i++;
            }
            i--;

            res.push_back({start, end});
            start = -1;
            end = -1;
        }

        return res;
    }
};
