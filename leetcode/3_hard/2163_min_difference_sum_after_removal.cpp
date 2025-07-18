#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

class Solution {
  public:
    long long minimumDifference(std::vector<int> &nums) {
        const int n = nums.size() / 3;
        std::vector<long long> min_sum(n + 1, 0);
        std::priority_queue<int> max_pq;
        long long sum = 0;
        int i = 0;
        for (; i < n; i++) {
            max_pq.push(nums[i]);
            sum += nums[i];
        }
        min_sum[0] = sum;
        for (; i < 2 * n; i++) {
            max_pq.push(nums[i]);
            sum += nums[i];
            sum -= max_pq.top();
            max_pq.pop();
            min_sum[i - n + 1] = sum;
        }
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
        sum = 0;
        i = 3 * n - 1;
        for (; i >= 2 * n; i--) {
            min_pq.push(nums[i]);
            sum += nums[i];
        }
        long long res = min_sum[n] - sum;
        for (/* 2n - 1 */; i >= n; i--) {
            min_pq.push(nums[i]);
            sum += nums[i];
            sum -= min_pq.top();
            min_pq.pop();
            res = std::min(res, min_sum[i - n] - sum);
        }

        return res;
    }
};
