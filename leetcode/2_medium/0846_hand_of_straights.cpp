#include <map>
#include <vector>

class Solution {
  public:
    bool isNStraightHand(std::vector<int> &hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        std::map<int, int> freqs;
        for (int card : hand) {
            freqs[card]++;
        }

        while (freqs.empty() == false) {
            auto [start, _] = *freqs.begin();
            for (int i = start; i < start + groupSize; i++) {
                if (freqs[i]) {
                    freqs[i]--;
                    if (freqs[i] == 0) {
                        freqs.erase(i);
                    }
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
