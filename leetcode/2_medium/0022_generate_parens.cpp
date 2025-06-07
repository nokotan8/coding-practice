// https://leetcode.com/problems/generate-parentheses
#include <string>
#include <vector>

using std::string;
class Solution {
  public:
    std::vector<string> res;
    std::vector<string> generateParenthesis(int n) {
        std::vector<int> parens = {0, 0};
        generate("", n, parens);

        return res;
    }
    void generate(string curr, int n, std::vector<int> parens) {
        if (parens[0] == n && parens[1] == n) {
            res.push_back(curr);
        } else {
            if (parens[0] < n) {
                parens[0]++;
                generate(curr + '(', n, parens);
                parens[0]--;
            }
            if (parens[0] > parens[1]) {
                parens[1]++;
                generate(curr + ')', n, parens);
            }
        }
    }
};
