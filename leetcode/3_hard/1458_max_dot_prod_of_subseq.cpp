#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    const int INF = 1e8;
public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        // dp[i][j]: max dot product from subarrays nums1[0:i-1], nums2[0:j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -INF));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = max({
                    nums1[i - 1] * nums2[j - 1],
                    nums1[i - 1] * nums2[j - 1] + dp[i - 1][j - 1],
                    dp[i - 1][j],
                    dp[i][j - 1]
                });
            }
        }

        return dp[m][n];
    }
};

// class Solution {
// public:
//     int recurse(vector<int> &nums1, vector<int> &nums2, vector<vector<int>>
//     &dp,
//                 int i, int j) {
//         if (dp[i][j] != INT_MIN) {
//             return dp[i][j];
//         }
//
//         int val = dp[i][j];
//         val = max(val, nums1[i] * nums2[j]);
//         if (i < nums1.size() - 1 && j < nums2.size() - 1)
//             val = max(val, nums1[i] * nums2[j] + recurse(nums1, nums2, dp, i
//             + 1, j + 1));
//         if (i < nums1.size() - 1)
//             val = max(val, recurse(nums1, nums2, dp, i + 1, j));
//         if (j < nums2.size() - 1)
//             val = max(val, recurse(nums1, nums2, dp, i, j + 1));
//
//         dp[i][j] = val;
//         return val;
//     }
//
//     int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
//         int m = nums1.size();
//         int n = nums2.size();
//         // dp[i][j]: max dot product from subarrays nums1[i:], nums2[j:]
//         vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
//
//         dp[m - 1][n - 1] = nums1.back() * nums2.back();
//
//         return recurse(nums1, nums2, dp, 0, 0);
//     }
// };
