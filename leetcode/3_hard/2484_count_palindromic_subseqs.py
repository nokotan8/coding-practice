class Solution:
    def countPalindromes(self, s: str) -> int:
        res = 0
        modu = pow(10, 9) + 7
        for x in range(0, 10):
            for y in range(0, 10):
                pattern = f"{x}{y}_{y}{x}"
                # dp[i] = # of subsequences that match 5 - i chars
                dp = [0] * 5 + [1]
                for i in range(len(s) - 1, -1, -1):
                    for j in range(0, 5):
                        if s[i] == pattern[j] or j == 2:
                            dp[j] += dp[j + 1]

                res = (res + dp[0]) % modu

        return res
