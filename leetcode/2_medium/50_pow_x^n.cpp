class Solution {
  public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        } else if (n == 0) {
            return 1;
        } else if (n > 0) {
            double ans = myPow(x, n / 2);
            ans *= ans;
            if (n & 1)
                ans *= x;

            return ans;
        } else {
            double ans = myPow(x, -(unsigned int)n / 2);
            ans *= ans;
            if (n & 1)
                ans *= x;

            return 1 / ans;
        }
    }
};
