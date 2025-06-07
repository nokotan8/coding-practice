#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
class Solution {
  public:
    size_t n;
    std::pair<size_t, size_t> square_to_coords(size_t sq) {
        size_t bot_row = (sq - 1) / n;
        size_t row = (n - 1) - bot_row;
        size_t col = (sq - 1) % n;
        if (bot_row % 2)
            col = (n - 1) - col;
        return {row, col};
    }
    int snakesAndLadders(std::vector<std::vector<int>> &board) {
        n = board.size();
        size_t end_sq = n * n;
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
        std::queue<size_t> q;
        q.push(1);
        visited[n - 1][0] = true;

        int steps = 0;
        while (q.empty() == false) {
            int q_size = q.size();
            while (q_size) {
                q_size--;
                size_t curr = q.front();
                q.pop();
                if (curr == end_sq)
                    return steps;

                size_t max_sq = std::min(curr + 6, end_sq);
                for (size_t i = curr + 1; i <= max_sq; i++) {
                    auto [row, col] = square_to_coords(i);
                    if (visited[row][col] == false) {
                        visited[row][col] = true;
                        if (board[row][col] == -1)
                            q.push(i);
                        else
                            q.push(board[row][col]);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
