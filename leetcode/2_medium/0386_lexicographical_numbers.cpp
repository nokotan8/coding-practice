/* Recursive, not O(1) space */
#include <algorithm>
#include <vector>
class Solution {
  public:
    void dfs(int curr, int n, std::vector<int> &res) {
        for (int i = 0; i <= 9; i++) {
            int new_num = curr * 10 + i;
            if (new_num > n)
                break;
            res.push_back(new_num);
            dfs(new_num, n, res);
        }
    }

    std::vector<int> lexicalOrder(int n) {
        std::vector<int> res;

        for (int i = 1; i <= std::min(9, n); i++) {
            res.push_back(i);
            dfs(i, n, res);
        }

        return res;
    }
};
