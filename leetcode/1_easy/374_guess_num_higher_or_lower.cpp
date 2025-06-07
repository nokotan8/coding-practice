int guess(int num);

class Solution {
  public:
    int guessNumber(int n) {
        int lo = 1;
        int hi = n;

        while (lo <= hi) {
            int md = ((long)lo + (long)hi) / 2;
            int res = guess(md);
            if (res == 0) {
                return md;
            } else if (res == 1) {
                lo = md + 1;
            } else {
                hi = md;
            }
        }

        return 0;
    }
};
