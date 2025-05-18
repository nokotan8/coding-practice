#include <cmath>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
  public:
    int colorTheGrid(int m, int n) {
        const int mod = 1e9 + 7;
        // Total # of combinations for each row
        const int total = std::pow(3, m);
        // All valid cols and their ternary rep, i.e. no two adj colours equal
        std::unordered_map<int, std::vector<int>> valid_cols;
        for (int i = 0; i < total; i++) {
            std::vector<int> ternary_rep(m);
            int curr = i;
            for (int j = 0; j < m; j++) {
                ternary_rep[j] = curr % 3;
                curr /= 3;
            }
            bool valid = true;
            for (int k = 1; k < m; k++) {
                if (ternary_rep[k] == ternary_rep[k - 1]) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                valid_cols[i] = ternary_rep;
        }

        // For each column, construct list of all valid adjacent columns
        std::unordered_map<int, std::vector<int>> valid_adj;
        for (auto &[col, col_ternary] : valid_cols) {
            for (auto &[col2, col2_ternary] : valid_cols) {
                bool valid = true;
                for (int i = 0; i < m; i++) {
                    if (col_ternary[i] == col2_ternary[i]) {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                    valid_adj[col].push_back(col2);
            }
        }

        // dp1[i] = # of combinations ending with column i
        std::vector<int> dp1(total, 0);
        for (auto &[col, _] : valid_cols) {
            dp1[col] = 1;
        }

        // dp1 is prev column, dp2 is curr
        for (int i = 1; i < n; i++) {
            std::vector<int> dp2(total, 0);
            for (auto &[col1, _] : valid_cols) {
                for (int adj : valid_adj[col1]) {
                    dp2[col1] = (dp2[col1] + dp1[adj]) % mod;
                }
            }

            // move curr to prev and continue to next col
            dp1 = std::move(dp2);
        }

        int ans = 0;
        for (auto &[col, _] : valid_cols) {
            ans = (ans + dp1[col]) % mod;
        }

        return ans;
    }
};
