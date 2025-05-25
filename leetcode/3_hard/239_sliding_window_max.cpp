/* Double-ended Queue */
#include <deque>
#include <vector>
class Solution {
  public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
        std::vector<int> res(nums.size() - k + 1);
        std::deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            if (i >= k - 1) {
                while (!dq.empty() && dq.front() <= i - k) {
                    dq.pop_front();
                }
                res[i - k + 1] = nums[dq.front()];
            }
        }
        return res;
    }
};

/* Priority Queue */
// #include <queue>
// #include <vector>
// class Solution {
//   public:
//     std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
//         std::vector<int> res;
//         std::priority_queue<std::pair<int, int>> pq;
//         for (int i = 0; i < k; i++) {
//             pq.push({nums[i], i});
//         }
//         res.push_back(pq.top().first);
//
//         for (int i = 1; i <= nums.size() - k; i++) {
//             pq.push({nums[i + k - 1], i + k - 1});
//             while (pq.top().second < i) {
//                 pq.pop();
//             }
//             res.push_back(pq.top().first);
//         }
//
//         return res;
//     }
// };
