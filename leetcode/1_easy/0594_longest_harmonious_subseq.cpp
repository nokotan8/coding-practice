/**
 * Sorting
 * TC: O(n logn)
 * SC: O(1)
 */
#include <algorithm>
#include <vector>

class Solution {
  public:
    int findLHS(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());

        int l = 0;
        int r = 0;
        int res = 0;
        while (r < nums.size()) {
            while (l < r && nums[r] - nums[l] > 1) {
                l++;
            }
            if (nums[r] - nums[l] == 1) {
                res = std::max(res, r - l + 1);
            }
            r++;
        }

        return res;
    }
};

/**
 * Hash map
 * TC: O(n) (but it actually runs slower than above)
 * SC: O(n)
 */
// #include <algorithm>
// #include <unordered_map>
// #include <vector>
// class Solution {
//   public:
//     int findLHS(std::vector<int> &nums) {
//         std::unordered_map<int, int> seen;
//
//         int res = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             seen[nums[i]]++;
//             if (seen[nums[i] + 1]) {
//                 res = std::max(res, seen[nums[i]] + seen[nums[i] + 1]);
//             }
//             if (seen[nums[i] - 1]) {
//                 res = std::max(res, seen[nums[i]] + seen[nums[i] - 1]);
//             }
//         }
//
//         return res;
//     }
// };
