#include <string>
#include <vector>

class Solution {
  private:
    std::vector<std::string> res;
    int n;

    void recurse(std::string &s, int ex, int total) {
        if (s.size() == n * 2) {
            res.push_back(s);
            return;
        }

        // Total '(' not reached max.
        if (total < n) {
            s.push_back('(');
            recurse(s, ex + 1, total + 1);
            s.pop_back();
        }
        // Excess forward parens.
        if (ex > 0) {
            s.push_back(')');
            recurse(s, ex - 1, total);
            s.pop_back();
        }
    }

  public:
    std::vector<std::string> generateParenthesis(int _n) {
        n = _n;
        std::string s;
        recurse(s, 0, 0);

        return res;
    }
};
