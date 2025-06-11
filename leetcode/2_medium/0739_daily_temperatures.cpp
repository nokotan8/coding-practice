/* Stack back to front */
#include <stack>
#include <vector>

class Solution {
  public:
    std::vector<int> dailyTemperatures(std::vector<int> &temps) {
        const int n = (int)temps.size();
        std::vector<int> ans(n, 0);
        std::stack<int> temps_right;

        for (int i = n - 1; i >= 0; i--) {
            while (temps_right.empty() == false &&
                   temps[i] >= temps[temps_right.top()]) {
                temps_right.pop();
            }
            if (temps_right.empty() == false) {
                ans[i] = temps_right.top() - i;
            }

            temps_right.push(i);
        }

        return ans;
    }
};

/* Stack front to back */
// #include <stack>
// #include <vector>
//
// class Solution {
//   public:
//     std::vector<int> dailyTemperatures(std::vector<int> &temps) {
//         const int n = (int)temps.size();
//         std::vector<int> ans(n, 0);
//         std::stack<int> temps_left;
//
//         for (int i = 0; i < n; i++) {
//             while (temps_left.empty() == false &&
//                    temps[i] > temps[temps_left.top()]) {
//                 ans[temps_left.top()] = i - temps_left.top();
//                 temps_left.pop();
//             }
//
//             temps_left.push(i);
//         }
//
//         return ans;
//     }
// };

/* PQ */
// #include <functional>
// #include <queue>
// #include <utility>
// #include <vector>
//
// class Solution {
//   public:
//     std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
//         const size_t n = temperatures.size();
//         std::priority_queue<std::pair<int, int>,
//                             std::vector<std::pair<int, int>>,
//                             std::greater<std::pair<int, int>>>
//             pq;
//         std::vector<int> ans(n, 0);
//
//         pq.push({temperatures[0], 0});
//
//         for (size_t i = 1; i < n; i++) {
//             while (pq.empty() == false && pq.top().first < temperatures[i]) {
//                 ans[pq.top().second] = i - pq.top().second;
//                 pq.pop();
//             }
//
//             pq.push({temperatures[i], i});
//         }
//
//         return ans;
//     }
// };
