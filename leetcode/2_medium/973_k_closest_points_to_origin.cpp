#include <functional>
#include <queue>
#include <utility>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>>
    kClosest(std::vector<std::vector<int>> &points, int k) {
        std::vector<std::vector<int>> res(k);

        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>>
            pq;

        for (size_t i = 0; i < points.size(); i++) {
            pq.push(
                {points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
        }

        for (int i = 0; i < k; i++) {
            res[i] = points[pq.top().second];
            pq.pop();
        }

        return res;
    }
};
