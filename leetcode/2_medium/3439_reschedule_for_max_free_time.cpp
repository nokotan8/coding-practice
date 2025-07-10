#include <algorithm>
#include <vector>

class Solution {
  public:
    int maxFreeTime(int eventTime, int k, std::vector<int> &startTime,
                    std::vector<int> &endTime) {
        const int n = startTime.size();

        int max_time = 0;
        int l = 0;
        int r = 0;
        int meeting_time = 0;

        while (r < n) {
            meeting_time += endTime[r] - startTime[r];
            if (r - l < k - 1) {
                r++;
                continue;
            }

            int start = l > 0 ? endTime[l - 1] : 0;
            int end = r != n - 1 ? startTime[r + 1] : eventTime;
            max_time = std::max(max_time, end - start - meeting_time);

            meeting_time -= endTime[l] - startTime[l];
            l++;
            r++;
        }

        return max_time;
    }
};
