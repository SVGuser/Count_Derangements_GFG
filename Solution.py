// Dynamic Programming Approach
class Solution:
    def derangeCount(self, n: int) -> int:
        if n == 1:
            return 0
        if n == 2:
            return 1

        dp = [0] * (n + 1)
        dp[1] = 0
        dp[2] = 1

        for i in range(3, n + 1):
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2])

        return dp[n]
// Recursive Memoization
from functools import lru_cache

class Solution:
    @lru_cache(None)
    def derangeCount(self, n: int) -> int:
        if n == 1:
            return 0
        if n == 2:
            return 1
        return (n - 1) * (self.derangeCount(n - 1) + self.derangeCount(n - 2))

  // Precomputed Table (for small n)

class Solution:
    def derangeCount(self, n: int) -> int:
        pre = [0, 0, 1, 2, 9, 44, 265, 1854]  # !n for n=0..7
        if n < len(pre):
            return pre[n]
        # fallback to DP if larger
        dp = [0] * (n + 1)
        dp[1], dp[2] = 0, 1
        for i in range(3, n + 1):
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2])
        return dp[n]
