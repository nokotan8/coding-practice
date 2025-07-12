#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

class Solution {
  public:
    int mostBooked(int n, std::vector<std::vector<int>> &meetings) {
        std::sort(meetings.begin(), meetings.end());
        std::vector<int> count(n, 0);
        std::priority_queue<int, std::vector<int>, std::greater<int>> free;
        std::priority_queue<std::pair<long long, int>,
                            std::vector<std::pair<long long, int>>,
                            std::greater<std::pair<long long, int>>>
            in_progress;
        for (int i = 0; i < n; i++) {
            free.push(i);
        }

        for (auto &meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            while (in_progress.size() && in_progress.top().first <= start) {
                free.push(in_progress.top().second);
                in_progress.pop();
            }

            if (free.size()) {
                in_progress.emplace(end, free.top());
                count[free.top()]++;
                free.pop();
            } else {
                auto [next_time, next_room] = in_progress.top();
                in_progress.pop();
                in_progress.emplace(end - start + next_time, next_room);
                count[next_room]++;
            }
        }

        int max = count[0];
        int max_idx = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > max) {
                max = count[i];
                max_idx = i;
            }
        }

        return max_idx;
    }
};
