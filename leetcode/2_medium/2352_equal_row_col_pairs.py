class Solution:
    def equalPairs(self, grid) -> int:
        ans = 0
        n = len(grid)
        rows = {}

        for row in grid:
            row_tuple = tuple(row)
            rows[row_tuple] = rows.get(row_tuple, 0) + 1

        curr_col = [0] * n
        for i in range(0, n):
            for j in range(0, n):
                curr_col[j] = grid[j][i]
            ans += rows.get(tuple(curr_col), 0)

        return ans
