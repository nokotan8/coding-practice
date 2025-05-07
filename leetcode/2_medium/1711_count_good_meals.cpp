#include <unordered_map>
#include <vector>
class Solution {
  public:
    int countPairs(std::vector<int> &deliciousness) {
        std::vector<int> pow(22, 0);

        int p = 1;
        for (int i = 0; i < 22; i++, p *= 2) {
            pow[i] = p;
        }

        long long ans = 0;
        int mod = 1e9 + 7;
        std::unordered_map<int, int> d;

        for (int n : deliciousness) {
            for (int i = 0; i <= 21; i++) {
                if (n > pow[i])
                    continue;
                if (d[pow[i] - n]) {
                    ans += d[pow[i] - n];
                    ans %= mod;
                }
            }
            d[n]++;
        }

        return ans;
    }
};
