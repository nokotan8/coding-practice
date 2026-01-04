#include <algorithm>
#include <cmath>
#include <vector>

class Solution {
private:
    std::vector<bool> sieve(int n) {
        std::vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        return is_prime;
    }

  public:
    int sumFourDivisors(std::vector<int> &nums) {
        std::vector<bool> is_prime = sieve(*std::max_element(nums.begin(), nums.end()));

        int res = 0;
        for (int num : nums) {
            int cb = (int)std::cbrt(num);
            if (is_prime[cb] && cb * cb * cb == num) {
                // p ^ 3
                res += (1 + cb + cb * cb + num);
            } else {
                // p * q, p != q
                for (int i = 2; i * i <= num; i++) {
                    if (num % i == 0) {
                        int j = num / i;
                        if (j != i && is_prime[i] && is_prime[j]) {
                            res += (1 + i + j + num);
                        }
                        break;
                    }
                }
            }
        }

        return res;
    }
};
