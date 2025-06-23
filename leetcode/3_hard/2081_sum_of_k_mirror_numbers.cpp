class Solution {
  private:
    int digits[100];
    bool is_base_k_palindrome(long long x, int k) {
        int idx = 0;
        while (x != 0) {
            digits[idx++] = x % k;
            x /= k;
        }

        for (int i = 0; i < (idx / 2); i++) {
            if (digits[i] != digits[idx - i - 1]) {
                return false;
            }
        }

        return true;
    }

  public:
    long long kMirror(int k, int n) {
        long long res = 0;
        int num = 1;
        for (int i = 1; num <= n; i *= 10) {
            int next = i * 10;
            for (int even = 0; even < 2; even++) {
                for (int j = i; j < next && num <= n; j++) {
                    int tmp = j;
                    long long pal = tmp;
                    if (even == 0) {
                        tmp /= 10;
                    }
                    while (tmp != 0) {
                        pal = pal * 10 + tmp % 10;
                        tmp /= 10;
                    }

                    if (is_base_k_palindrome(pal, k)) {
                        num++;
                        res += pal;
                    }
                }
            }
        }

        return res;
    }
};
