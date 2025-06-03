#include <algorithm>
#include <vector>
class Solution {
  public:
    bool can_eat_all(std::vector<int> &piles, int limit, long spd) {
        long hours = 0;
        for (int p : piles) {
            hours += (p + spd - 1) / spd;
        }

        return hours <= (long)limit;
    }
    int minEatingSpeed(std::vector<int> &piles, int h) {
        int max_pile = piles[0];

        for (size_t i = 1; i < piles.size(); i++) {
            max_pile = std::max(max_pile, piles[i]);
        }

        int lo = 1;
        int hi = max_pile;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (can_eat_all(piles, h, mid))
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        return lo;
    }
};
