#include <unordered_map>
#include <vector>
class Solution {
  private:
    std::vector<std::vector<int>> res;

    void backtrack(std::vector<int> &curr, std::unordered_map<int, int> &freq,
                   int rem) {
        if (rem == 0) {
            res.push_back(curr);
            return;
        }

        for (auto &[num, f] : freq) {
            if (f > 0) {
                f--;
                curr.push_back(num);

                backtrack(curr, freq, rem - 1);

                curr.pop_back();
                f++;
            }
        }
    }

  public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
        std::unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        std::vector<int> curr;
        backtrack(curr, freq, nums.size());

        return res;
    }
};
