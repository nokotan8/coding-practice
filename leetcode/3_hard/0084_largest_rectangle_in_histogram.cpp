#include <algorithm>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

/* One pass */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();
        stack<pair<int, int>> st; // index, height
        int res = 0;

        st.emplace(0, heights[0]);

        for (int i = 1; i < n; i++) {
            int left = i;
            while (st.size() && st.top().second >= heights[i]) {
                res = max(res, st.top().second * (i - st.top().first));
                left = st.top().first;
                st.pop();
            }

            st.emplace(left, heights[i]);
        }
        while (st.size()) {
            res = max(res, st.top().second * (n - st.top().first));
            st.pop();
        }

        return res;
    }
};

/* Two pass */
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         const int n = heights.size();
//
//         vector<int> left(n, 0);
//         vector<int> right(n, 0);
//         stack<int> st;
//
//         for (int i = 0; i < n; i++) {
//             while (st.size() && heights[st.top()] >= heights[i]) {
//                 st.pop();
//             }
//
//             if (st.size()) {
//                 left[i] = st.top() + 1;
//             } else {
//                 left[i] = 0;
//             }
//
//             st.push(i);
//         }
//
//         while (st.size()) {
//             st.pop();
//         }
//
//         for (int i = n - 1; i >= 0; i--) {
//             while (st.size() && heights[st.top()] >= heights[i]) {
//                 st.pop();
//             }
//
//             if (st.size()) {
//                 right[i] = st.top() - 1;
//             } else {
//                 right[i] = n - 1;
//             }
//
//             st.push(i);
//         }
//
//         int res = 0;
//         for (int i = 0; i < n; i++) {
//             res = max(res, (right[i] - left[i] + 1) * heights[i]);
//         }
//
//         return res;
//     }
// };
