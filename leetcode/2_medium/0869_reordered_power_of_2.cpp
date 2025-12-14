#include <algorithm>
#include <string>
#include <unordered_set>

class Solution {
  public:
    bool reorderedPowerOf2(int n) {
        std::unordered_set<std::string> powers;

        for (int i = 0, p = 1; i < 30; i++, p *= 2) {
            std::string p_str = std::to_string(p);
            std::sort(p_str.begin(), p_str.end());

            powers.insert(p_str);
        }

        std::string n_str = std::to_string(n);
        std::sort(n_str.begin(), n_str.end());

        return powers.count(n_str) == 1;
    }
};
