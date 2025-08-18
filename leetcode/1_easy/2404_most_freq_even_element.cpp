#include <unordered_map>
#include <vector>

class Solution {
  public:
    int mostFrequentEven(std::vector<int> &nums) {
        int max_freq = -1;
        int max_ele = -1;
        std::unordered_map<int, int> count;

        for (int num : nums) {
            if ((num & 1) == 0) {
                count[num]++;
                if (count[num] > max_freq ||
                    (num < max_ele && count[num] == max_freq)) {
                    max_ele = num;
                    max_freq = count[num];
                }
            }
        }

        return max_ele;
    }
};
