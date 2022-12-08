from typing import List


class Solution:

    def maxProfit(self, prices: List[int]) -> int:
        min_price = 10000
        profit = 0

        for current_price in prices:
            min_price = min(min_price, current_price)
            profit = max(profit, current_price - min_price)

        return profit