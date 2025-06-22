#include <vector>

#define get_subbox(x, y) (((x) / 3) * 3 + ((y) / 3))

class Solution {
  public:
    bool isValidSudoku(std::vector<std::vector<char>> &board) {
        std::vector<std::vector<bool>> rows(9, std::vector<bool>(10, false));
        std::vector<std::vector<bool>> cols(9, std::vector<bool>(10, false));
        std::vector<std::vector<bool>> boxes(9, std::vector<bool>(10, false));

        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    int square = board[i][j] - '0';
                    int subbox = get_subbox(i, j);

                    if (rows[i][square] || cols[j][square] ||
                        boxes[subbox][square]) {
                        return false;
                    }

                    rows[i][square] = true;
                    cols[j][square] = true;
                    boxes[subbox][square] = true;
                }
            }
        }

        return true;
    }
};
