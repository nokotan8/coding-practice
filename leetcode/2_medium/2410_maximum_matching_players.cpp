#include <algorithm>
#include <vector>
class Solution {
  public:
    int matchPlayersAndTrainers(std::vector<int> &players,
                                std::vector<int> &trainers) {
        std::sort(players.begin(), players.end());
        std::sort(trainers.begin(), trainers.end());
        int res = 0;

        int i = 0;
        int j = 0;
        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                res++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        return res;
    }
};
