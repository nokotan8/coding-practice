#include <algorithm>
#include <queue>
#include <vector>
class Solution {
  public:
    static bool query_compare(std::vector<int> &q1, std::vector<int> &q2) {
        return q1[0] < q2[0];
    }

    int maxRemoval(std::vector<int> &nums,
                   std::vector<std::vector<int>> &queries) {
        std::sort(queries.begin(), queries.end(), query_compare);
        std::vector<int> delta(nums.size() + 1, 0);
        std::priority_queue<int> pq;

        int ops = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            ops += delta[i];
            for (; j < queries.size() && queries[j][0] == i; j++) {
                pq.push(queries[j][1]);
            }
            while (ops < nums[i] && pq.size() && pq.top() >= i) {
                ops += 1;
                delta[pq.top() + 1]--;
                pq.pop();
            }
            if (ops < nums[i]) {
                return -1;
            }
        }

        return pq.size();
    }
};
