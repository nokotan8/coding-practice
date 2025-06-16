#include <string>
#include <vector>

class Solution {
  public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        m = s1.size();
        n = s2.size();
        p = s3.size();

        dp = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, -1));
        if (m + n != p) {
            return false;
        }

        return recurse(0, 0, 0);
    }

  private:
    bool recurse(int idx1, int idx2, int idx3) {
        if (idx3 == p) {
            return true;
        } else if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }

        bool res = false;
        if (idx1 < m && s1[idx1] == s3[idx3]) {
            res = recurse(idx1 + 1, idx2, idx3 + 1);
        }

        if (res == false && idx2 < n && s2[idx2] == s3[idx3]) {
            res = recurse(idx1, idx2 + 1, idx3 + 1);
        }

        dp[idx1][idx2] = res;
        return res;
    }

    std::vector<std::vector<int>> dp;

    std::string s1;
    std::string s2;
    std::string s3;

    int m;
    int n;
    int p;
};
