#include <algorithm>
#include <vector>
class Solution {
  public:
    long long minSum(std::vector<int> &nums1, std::vector<int> &nums2) {
        long long sum1 = 0;
        int zero_count1 = 0;
        long long sum2 = 0;
        int zero_count2 = 0;
        for (int num : nums1) {
            if (num == 0) {
                zero_count1++;
            } else {
                sum1 += num;
            }
        }
        for (int num : nums2) {
            if (num == 0) {
                zero_count2++;
            } else {
                sum2 += num;
            }
        }

        sum1 += zero_count1;
        sum2 += zero_count2;
        if ((sum1 < sum2 && zero_count1 == 0) ||
            (sum1 > sum2 && zero_count2 == 0)) {
            return -1;
        }

        return std::max(sum1, sum2);
    }
};
