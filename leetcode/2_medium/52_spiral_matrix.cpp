// Pretty sure this is way more complicated than it needs to be
#include <unordered_set>
#include <vector>
class Solution {
  public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int direction = 0;
        std::unordered_set<int> visited_rows;
        std::unordered_set<int> visited_cols;

        struct cell {
            int row = 0;
            int col = 0;
        } curr_cell;

        std::vector<int> res(rows * cols);
        int curr_i = 0;
        while (curr_i < res.size()) {
            switch (direction) {
                case 0:
                    while (curr_cell.col < cols &&
                        !visited_cols.count(curr_cell.col)) {
                        res[curr_i++] = matrix[curr_cell.row][curr_cell.col++];
                    }
                    curr_cell.col--;
                    visited_rows.insert(curr_cell.row);
                    curr_cell.row++;
                    break;
                case 1:
                    while (curr_cell.row < rows &&
                        !visited_rows.count(curr_cell.row)) {
                        res[curr_i++] = matrix[curr_cell.row++][curr_cell.col];
                    }
                    curr_cell.row--;
                    visited_cols.insert(curr_cell.col);
                    curr_cell.col--;
                    break;
                case 2:
                    while (curr_cell.col >= 0 &&
                        !visited_cols.count(curr_cell.col)) {
                        res[curr_i++] = matrix[curr_cell.row][curr_cell.col--];
                    }
                    curr_cell.col++;
                    visited_rows.insert(curr_cell.row);
                    curr_cell.row--;
                    break;
                case 3:
                    while (curr_cell.row >= 0 &&
                        !visited_rows.count(curr_cell.row)) {
                        res[curr_i++] = matrix[curr_cell.row--][curr_cell.col];
                    }
                    curr_cell.row++;
                    visited_cols.insert(curr_cell.col);
                    curr_cell.col++;
                    break;
            }

            direction = (direction + 1) % 4;
        }

        return res;
    }
};
