#include <vector>
class Solution {
  public:
    void sortColors(std::vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        int i = 0;
        while (i <= r) {
            if (nums[i] == 2) {
                int tmp = nums[i];
                nums[i] = nums[r];
                nums[r--] = tmp;
            } else if (nums[i] == 0) {
                int tmp = nums[i];
                nums[i] = nums[l];
                nums[l++] = tmp;
                i++;
            } else {
                i++;
            }
        }
    }
};
