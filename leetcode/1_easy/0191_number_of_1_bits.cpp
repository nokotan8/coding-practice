/* Lmao? */
// class Solution {
// public:
//     int hammingWeight(int n) {
//         return __builtin_popcount(n);
//     }
// };

/* Ok fine I'll do it properly */
class Solution {
  public:
    int hammingWeight(int n) {
        int res = 0;
        while (n) {
            // Removes least significant bit. E.g. 10100 & 10011 = 10000. From:
            // https://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan
            n = n & (n - 1);
            res++;
        }

        return res;
    }
};
