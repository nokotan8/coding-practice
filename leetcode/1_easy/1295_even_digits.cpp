// https://leetcode.com/problems/find-numbers-with-even-number-of-digits
#include <vector>

class Solution {
  public:
    int findNumbers(std::vector<int> &nums) {
        int count = 0;
        for (int num : nums) {
            int digits = 0;
            while (num != 0) {
                num /= 10;
                digits++;
            }
            if (!(digits % 2)) {
                count++;
            }
        }
        return count;
    }
};
