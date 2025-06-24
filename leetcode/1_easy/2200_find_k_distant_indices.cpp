/* Track min unadded index (?): O(n) time, O(1) space */
#include <algorithm>
#include <vector>

class Solution {
  public:
    std::vector<int> findKDistantIndices(std::vector<int> &nums, int key,
                                         int k) {
        const int n = (int)nums.size();
        std::vector<int> res;
        int rem = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int l = std::max(0, i - k);
                int r = std::min(i + k, n - 1);
                for (int j = std::max(rem, l); j <= r; j++) {
                    res.push_back(j);
                }
                rem = r + 1;
            }
        }
        return res;
    }
};

/* Difference array: O(n) time, O(n) space */
// #include <algorithm>
// #include <vector>
//
// class Solution {
//   public:
//     std::vector<int> findKDistantIndices(std::vector<int> &nums, int key,
//                                          int k) {
//         const int n = (int)nums.size();
//         std::vector<int> res;
//         std::vector<int> delta(n + 1, 0);
//         for (int i = 0; i < n; i++) {
//             if (nums[i] == key) {
//                 delta[std::max(0, i - k)]++;
//                 delta[std::min(n, i + k + 1)]--;
//             }
//         }
//
//         for (int j = 0, sum = 0; j < n; j++) {
//             sum += delta[j];
//             if (sum > 0) {
//                 res.push_back(j);
//             }
//         }
//
//         return res;
//     }
// };
