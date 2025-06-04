#include <algorithm>
#include <stack>
#include <vector>
class Solution {
  public:
    int largestRectangleArea(std::vector<int> &heights) {
        const size_t n = heights.size();
        if (n == 1)
            return heights[0];
        std::vector<int> left_max(n, -1);
        std::vector<int> right_max(n, n);
        std::stack<int> s;

        for (size_t i = 0; i < n; i++) {
            while (s.empty() == false && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            if (s.empty()) {
                left_max[i] = 0;
            } else {
                left_max[i] = s.top() + 1;
            }

            s.push(i);
        }

        while (s.empty() == false)
            s.pop();

        for (int i = (int)n - 1; i >= 0; i--) {
            while (s.empty() == false && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            if (s.empty()) {
                right_max[i] = n - 1;
            } else {
                right_max[i] = s.top() - 1;
            }

            s.push(i);
        }

        int res = 0;
        for (size_t i = 0; i < n; i++) {
            int area = heights[i] * (right_max[i] - left_max[i] + 1);
            res = std::max(res, area);
        }

        return res;
    }
};
