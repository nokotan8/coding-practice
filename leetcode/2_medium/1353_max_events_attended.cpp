#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

class Solution {
  public:
    int maxEvents(std::vector<std::vector<int>> &events) {
        const int n = events.size();
        int max_day = 0;
        for (int i = 0; i < n; i++) {
            max_day = std::max(max_day, events[i][1]);
        }

        std::sort(events.begin(), events.end());
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        int res = 0;
        for (int day = 1, i = 0; day <= max_day; day++) {
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }
            while (pq.empty() == false && pq.top() < day) {
                pq.pop();
            }

            if (pq.empty() == false) {
                pq.pop();
                res++;
            }
        }

        return res;
    }
};
