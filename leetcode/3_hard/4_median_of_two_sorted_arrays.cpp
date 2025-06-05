#include <algorithm>
#include <climits>
#include <vector>
class Solution {
  public:
    double findMedianSortedArrays(std::vector<int> &nums1,
                                  std::vector<int> &nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();
        int l = 0;
        int r = m;

        while (l <= r) {
            int split_a = (l + r) / 2;
            int split_b = (m + n + 1) / 2 - split_a;

            int a_left = split_a == 0 ? INT_MIN : nums1[split_a - 1];
            int a_right = split_a == m ? INT_MAX : nums1[split_a];
            int b_left = split_b == 0 ? INT_MIN : nums2[split_b - 1];
            int b_right = split_b == n ? INT_MAX : nums2[split_b];

            if (a_left <= b_right && b_left <= a_right) {
                if ((m + n) & 1) {
                    return (double)std::max(a_left, b_left);
                } else {
                    return (std::max(a_left, b_left) +
                            std::min(a_right, b_right)) /
                           2.0;
                }
            }

            if (a_left > b_right) {
                r = split_a - 1;
            } else {
                l = split_a + 1;
            }
        }

        return 0;
    }
};
