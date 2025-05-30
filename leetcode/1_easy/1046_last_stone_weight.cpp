#include <queue>
#include <vector>
class Solution {
  public:
    int lastStoneWeight(std::vector<int> &stones) {
        std::priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (x != y)
                pq.push(y - x);
        }

        return pq.size() ? pq.top() : 0;
    }
};
