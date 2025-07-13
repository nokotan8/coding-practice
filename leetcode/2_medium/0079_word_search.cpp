#include <string>
#include <vector>

class Solution {
  private:
    std::vector<std::vector<int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    bool recurse(std::vector<std::vector<char>> &board, std::string &word,
                 int i, int j, int idx) {
        if (idx == word.size()) {
            return true;
        }

        for (auto &dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];

            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() &&
                board[x][y] == word[idx]) {
                board[x][y] = '-';
                if (recurse(board, word, x, y, idx + 1)) {
                    board[x][y] = word[idx];
                    return true;
                }
                board[x][y] = word[idx];
            }
        }

        return false;
    }

    bool exist(std::vector<std::vector<char>> &board, std::string word) {
        const size_t m = board.size();
        const size_t n = board[0].size();

        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '-';
                    if (recurse(board, word, i, j, 1)) {
                        return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }

        return false;
    }
};
