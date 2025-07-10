#include <algorithm>
#include <vector>

class Solution {
  public:
    int maxFreeTime(int eventTime, std::vector<int> &startTime,
                    std::vector<int> &endTime) {
        const int n = startTime.size();
        std::vector<int> spaces;
        spaces.push_back(startTime[0] - 0);
        for (int i = 0; i < n - 1; i++) {
            spaces.push_back(startTime[i + 1] - endTime[i]);
        }
        spaces.push_back(eventTime - endTime.back());

        std::vector<bool> rearrange(n, false);
        int max_gap = 0;
        for (int i = 0; i < n; i++) {
            if (max_gap >= endTime[i] - startTime[i])
                rearrange[i] = true;
            max_gap = std::max(max_gap, spaces[i]);
        }
        max_gap = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (max_gap >= endTime[i] - startTime[i])
                rearrange[i] = true;
            max_gap = std::max(max_gap, spaces[i + 1]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (rearrange[i]) {
                res = std::max(res, spaces[i] + endTime[i] - startTime[i] +
                                        spaces[i + 1]);
            } else {
                res = std::max(res, spaces[i] + spaces[i + 1]);
            }
        }

        return res;
    }
};
