#include <utility>
#include <vector>

class Solution {
  private:
    int m;
    int n;
    std::vector<std::pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void convert(std::vector<std::vector<char>> &board, int row, int col) {
        board[row][col] = 'N';
        for (auto [i, j] : directions) {
            int x = row + i;
            int y = col + j;
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {
                convert(board, x, y);
            }
        }
    }

  public:
    void solve(std::vector<std::vector<char>> &board) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                convert(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                convert(board, i, n - 1);
            }
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                convert(board, 0, j);
            }
            if (board[m - 1][j] == 'O') {
                convert(board, m - 1, j);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'N') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
