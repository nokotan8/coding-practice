#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution {
    /* From #84 */
    int max_area(vector<int>& heights) {
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

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;

        vector<int> heights(n, 0);
        for (auto &row : matrix) {
            for (int i = 0; i < n; i++) {
                if (row[i] == '0') {
                    heights[i] = 0;
                } else {
                    heights[i]++;
                }
            }

            res = max(res, max_area(heights));
        }

        return res;
    }
};
