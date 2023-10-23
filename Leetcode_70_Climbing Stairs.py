from functools import lru_cache


class Solution:

    @lru_cache
    def dfs(self, current_n: int, n: int):
        if current_n > n:
            return False
        elif current_n == n:
            return True
        else:
            return (self.dfs(current_n+1, n) + self.dfs(current_n+2, n))

    def climbStairs(self, n: int) -> int:
        return self.dfs(0, n)
