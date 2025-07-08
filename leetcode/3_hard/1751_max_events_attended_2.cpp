#include <algorithm>
#include <vector>

class Solution {
  private:
    std::vector<std::vector<int>> dp;
    std::vector<int> next_idx;

    // Returns first index where events[idx][0] > val
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
        int attend = events[idx][2] + recurse(events, next_idx[idx], rem - 1);

        return dp[idx][rem] = std::max(attend, no_attend);
    }

    int maxValue(std::vector<std::vector<int>> &events, int k) {
        std::sort(events.begin(), events.end());
        const int n = events.size();
        dp = std::vector<std::vector<int>>(n, std::vector<int>(k + 1, -1));
        next_idx = std::vector<int>(n);

        // Precompute next valid event for each index
        for (int i = 0; i < n; i++) {
            next_idx[i] = upper_bound(events, i + 1, n - 1, events[i][1]);
        }

        return recurse(events, 0, k);
    }
};
