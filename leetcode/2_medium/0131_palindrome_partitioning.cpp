#include <string>
#include <vector>

class Solution {
    std::vector<std::vector<std::string>> res;
    std::vector<std::vector<bool>> dp;
    inline void find_palindromes(std::string &s) {
        int n = s.size();
        dp = std::vector<std::vector<bool>> (n, std::vector<bool>(n, false));

        for (int l = 1; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                // For palindromes of length <= 3, as long as the end chars are equal,
                // it must be a palindrome.
                if (s[i] == s[i + l - 1] && (l <= 3 || dp[i + 1][i + l - 2])) {
                    dp[i][i + l - 1] = true;
                }
            }
        }
    }

    void recurse(std::string &s, std::vector<std::string> &path, int pos) {
        if (pos == s.size()) {
            res.push_back(path);
        }

        for (int i = pos; i < s.size(); i++) {
            if (dp[pos][i]) {
                path.push_back(s.substr(pos, i - pos + 1));
                recurse(s, path, i + 1);
                path.pop_back();
            }
        }
    }

public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        find_palindromes(s);
        std::vector<std::string> path;
        recurse(s, path, 0);

        return res;
    }
};
