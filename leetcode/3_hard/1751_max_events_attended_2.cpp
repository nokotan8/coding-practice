#include <algorithm>
#include <vector>

class Solution {
  private:
    std::vector<std::vector<int>> dp;

    int upper_bound(std::vector<std::vector<int>> &events, int lo, int hi,
                    int val) {
        while (lo <= hi) {
            int md = lo + (hi - lo) / 2;

            if (events[md][0] <= val) {
                lo = md + 1;
            } else {
                hi = md - 1;
            }
        }

        return lo;
    }

  public:
    int recurse(std::vector<std::vector<int>> &events, int idx, int rem) {
        if (idx == events.size() || rem == 0) {
            return 0;
        } else if (dp[idx][rem] != -1) {
            return dp[idx][rem];
        }

        int no_attend = recurse(events, idx + 1, rem);
        int next_idx =
            upper_bound(events, idx + 1, events.size() - 1, events[idx][1]);
        int attend = events[idx][2] + recurse(events, next_idx, rem - 1);

        return dp[idx][rem] = std::max(attend, no_attend);
    }

    int maxValue(std::vector<std::vector<int>> &events, int k) {
        dp = std::vector<std::vector<int>>(events.size(),
                                           std::vector<int>(k + 1, -1));
        std::sort(events.begin(), events.end());

        return recurse(events, 0, k);
    }
};
