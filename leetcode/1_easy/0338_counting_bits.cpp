#include <vector>
class Solution {
  public:
    std::vector<int> countBits(int n) {
        std::vector<int> res(n + 1);
        res[0] = 0;
        int offset = 1;

        for (int i = 1; i < n + 1; i++) {
            if (offset * 2 == i)
                offset *= 2;
            res[i] = 1 + res[i - offset];
        }

        return res;
    }
};
