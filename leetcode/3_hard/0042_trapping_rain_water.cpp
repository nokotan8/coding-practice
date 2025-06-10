/* O(n) 1 pass */
#include <algorithm>
#include <vector>
class Solution {
  public:
    int trap(std::vector<int> &height) {
        const size_t n = height.size();
        if (n < 3) {
            return 0;
        }
        int res = 0;

        int l = 0;
        int l_max = height[l];
        int r = n - 1;
        int r_max = height[r];

        while (l < r) {
            if (l_max < r_max) {
                l++;
                l_max = std::max(l_max, height[l]);
                res += l_max - height[l];
            } else {
                r--;
                r_max = std::max(r_max, height[r]);
                res += r_max - height[r];
            }
        }

        return res;
    }
};

/* O(n) 3 passes */
// #include <algorithm>
// #include <vector>
// class Solution {
//   public:
//     int trap(std::vector<int> &height) {
//         const size_t n = height.size();
//         if (n < 3) {
//             return 0;
//         }
//         int res = 0;
//         std::vector<int> max_left(n, 0);
//         std::vector<int> max_right(n, 0);
//
//         for (size_t i = 1; i < n; i++) {
//             max_left[i] = std::max(max_left[i - 1], height[i - 1]);
//         }
//         for (int i = (int)n - 2; i >= 0; i--) {
//             max_right[i] = std::max(max_right[i + 1], height[i + 1]);
//         }
//
//         for (size_t i = 1; i < n - 1; i++) {
//             res += std::max(std::min(max_left[i], max_right[i]) - height[i], 0);
//         }
//
//         return res;
//     }
// };
