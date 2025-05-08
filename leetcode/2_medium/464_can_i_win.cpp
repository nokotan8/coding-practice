#include <unordered_map>
class Solution {
  public:
    std::unordered_map<int, bool> dp;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        const int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (sum < desiredTotal) {
            return false;
        } else if (desiredTotal <= 0) {
            return true;
        }

        int state = 0;
        return calc(maxChoosableInteger, desiredTotal, state);
    }

    bool calc(int maxI, int desiredTotal, int state) {
        if (desiredTotal <= 0) {
            return false;
        } else if (dp.count(state)) {
            return dp[state];
        }

        int mask = 1;
        for (int i = 1; i <= maxI; i++, mask <<= 1) {
            if ((mask & state) == 0) {
                if (!calc(maxI, desiredTotal - i, mask | state)) {
                    dp[state] = true;
                    return true;
                }
            }
        }
        dp[mask] = false;
        return false;
    }
};
