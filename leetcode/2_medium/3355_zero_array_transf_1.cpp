#include <vector>
class Solution {
  public:
    bool isZeroArray(std::vector<int> &nums,
                     std::vector<std::vector<int>> &queries) {
        const int n = nums.size();
        std::vector<int> diff_arr(n + 1, 0);
        diff_arr[0] = nums[0];
        for (int i = 1; i < n; i++) {
            diff_arr[i] = nums[i] - nums[i - 1];
        }

        for (std::vector<int> &query : queries) {
            diff_arr[query[0]]--;
            diff_arr[query[1] + 1]++;
        }

        nums[0] = diff_arr[0];
        if (nums[0] > 0)
            return false;

        for (int i = 1; i < n; i++) {
            nums[i] = nums[i - 1] + diff_arr[i];
            if (nums[i] > 0)
                return false;
        }

        return true;
    }
};
