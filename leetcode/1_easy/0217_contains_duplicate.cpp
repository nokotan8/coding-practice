/* Using sorting */
#include <algorithm>
#include <vector>
class Solution {
  public:
    bool containsDuplicate(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }
};

/* Using set */
// #include <unordered_set>
// #include <vector>
// class Solution {
//   public:
//     bool containsDuplicate(std::vector<int> &nums) {
//         std::unordered_set<int> numset(nums.begin(), nums.end());
//
//         return nums.size() != numset.size();
//     }
// };
