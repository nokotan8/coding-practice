#include <stack>
#include <string>

class Solution {
  public:
    bool checkValidString(std::string s) {
        std::stack<int> open_p, wildcard;
        for (size_t i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '(':
                    open_p.push(i);
                    break;
                case ')':
                    if (open_p.size())
                        open_p.pop();
                    else if (wildcard.size())
                        wildcard.pop();
                    else
                        return false;
                    break;
                case '*':
                    wildcard.push(i);
                    break;
                default:
                    return false;
            }
        }

        while (open_p.size()) {
            if (wildcard.size() && open_p.top() < wildcard.top()) {
                open_p.pop();
                wildcard.pop();
            } else {
                return false;
            }
        }

        return open_p.empty();
    }
};

/* O(n^2) DP */
// #include <string>
// #include <vector>
// class Solution {
//     // dp[i][j] = whether the string is valid when there are
//     // j open parens when index i is reached.
//     // 0 = not calculated
//     // 1 = valid
//     // 2 = invalid
//     std::vector<std::vector<int>> dp;
//
//   public:
//     bool recurse(std::string &s, int idx, int open_p) {
//         if (idx == s.size())
//             return open_p == 0;
//         else if (dp[idx][open_p])
//             return dp[idx][open_p] == 1;
//
//         switch (s[idx]) {
//             case '(':
//                 dp[idx][open_p] = recurse(s, idx + 1, open_p + 1) ? 1 : 2;
//                 break;
//             case ')':
//                 if (open_p)
//                     dp[idx][open_p] = recurse(s, idx + 1, open_p - 1) ? 1 :
//                     2;
//                 else
//                     dp[idx][open_p] = 2;
//                 break;
//             case '*': {
//                 bool is_open_p = recurse(s, idx + 1, open_p + 1);
//                 bool is_empty = recurse(s, idx + 1, open_p);
//                 bool is_close_p = false;
//                 if (open_p)
//                     is_close_p = recurse(s, idx + 1, open_p - 1);
//
//                 dp[idx][open_p] = (is_open_p || is_close_p || is_empty) ? 1 :
//                 2; break;
//             }
//             default:
//                 return false;
//         }
//
//         return dp[idx][open_p] == 1;
//     }
//
//     bool checkValidString(std::string s) {
//         const size_t n = s.size();
//         dp = std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1,
//         0));
//
//         return recurse(s, 0, 0);
//     }
// };
