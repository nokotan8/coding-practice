#include <string>
#include <vector>

class Solution {
  public:
    std::vector<std::string> divideString(std::string s, int k, char fill) {
        std::vector<std::string> res((s.size() + k - 1) / k, "");

        for (size_t i = 0; i < s.size(); i++) {
            res[i / k].push_back(s[i]);
        }

        while (res.back().size() < k) {
            res.back().push_back(fill);
        }

        return res;
    }
};
