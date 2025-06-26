#include <cstdint>

class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        uint32_t mask = 1;
        for (int i = 0; i < 32; i++, mask <<= 1) {
            if (n & mask) {
                res |= (1 << (31 - i));
            }
        }

        return res;
    }
};
