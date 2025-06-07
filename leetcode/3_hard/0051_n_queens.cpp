#include <string>
#include <utility>
#include <vector>
class Solution {
  public:
    std::vector<std::vector<std::string>> res;
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        // state[i][j] = 0 : not occupied
        //             = 1 : occupied by queen
        //             = 2 : attacked by existing queen
        std::vector<std::vector<int>> state(n, std::vector<int>(n, 0));
        solve(0, state);

        return res;
    }

    void solve(int row, std::vector<std::vector<int>> &state) {
        const int n = state.size();
        if (row == n) {
            std::vector<std::string> curr_res(n, std::string(n, '.'));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (state[i][j] == 1)
                        curr_res[i][j] = 'Q';
                }
            }

            res.push_back(curr_res);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (state[row][j] != 2) {
                state[row][j] = 1;
                std::vector<std::pair<int, int>> attacked;

                for (int i = row + 1, off = 1; i < n; i++, off++) {
                    if (state[i][j] != 2) {
                        state[i][j] = 2;
                        attacked.push_back({i, j});
                    }
                    if (j - off >= 0 && state[i][j - off] != 2) {
                        state[i][j - off] = 2;
                        attacked.push_back({i, j - off});
                    }
                    if (j + off < n && state[i][j + off] != 2) {
                        state[i][j + off] = 2;
                        attacked.push_back({i, j + off});
                    }
                }

                solve(row + 1, state);

                state[row][j] = 0;
                for (auto &[x, y] : attacked) {
                    state[x][y] = 0;
                }
            }
        }
    }
};

/* Slightly cleaner using sets. Should be faster
 * in theory, but roughly equal when submitted. */
// #include <string>
// #include <unordered_set>
// #include <vector>
// class Solution {
//   public:
//     //  (i-1,j-1)           (i-1,j+1)
//     //              (i,j)
//     //  (i+1,j-1)           (i+1,j+1)
//     //
//     //  For diagonal from bottom-left to top-right passing
//     //  through (i,j), row + col = i + j;
//     //  For diagonal from bottom-right to top-left passing
//     //  through (i,j), row - col = i - j;
//     std::unordered_set<int> cols;
//     std::unordered_set<int> up_diag;
//     std::unordered_set<int> down_diag;
//
//     std::vector<std::vector<std::string>> res;
//
//     std::vector<std::vector<std::string>> solveNQueens(int n) {
//         std::vector<std::string> state(n, std::string(n, '.'));
//
//         solve(0, state);
//         return res;
//     }
//
//     void solve(int row, std::vector<std::string> &state) {
//         const int n = state.size();
//         if (row == n) {
//             res.push_back(state);
//         }
//
//         for (int col = 0; col < n; col++) {
//             if (cols.count(col) || up_diag.count(row + col) ||
//                 down_diag.count(row - col))
//                 continue;
//
//             state[row][col] = 'Q';
//             cols.insert(col);
//             up_diag.insert(row + col);
//             down_diag.insert(row - col);
//
//             solve(row + 1, state);
//
//             state[row][col] = '.';
//             cols.erase(col);
//             up_diag.erase(row + col);
//             down_diag.erase(row - col);
//         }
//     }
// };
