#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

class Solution {
  public:
    int carFleet(int target, std::vector<int> &position,
                 std::vector<int> &speed) {
        const int n = position.size();
        std::vector<std::pair<int, int>> cars;
        for (int i = 0; i < n; i++) {
            cars.emplace_back(position[i], speed[i]);
        }
        std::sort(cars.begin(), cars.end(), std::greater<>());

        int count = 0;
        double prev = -1.0;
        for (int i = 0; i < n; i++) {
            double curr_time = (1.0 * target - cars[i].first) / cars[i].second;
            if (curr_time > prev) {
                prev = curr_time;
                count++;
            }
        }

        return count;
    }
};
