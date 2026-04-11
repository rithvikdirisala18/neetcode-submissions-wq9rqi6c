class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        minPrice = prices[0]
        for p in prices:
            res = max(res, p-minPrice)
            minPrice = min(minPrice, p)
        return res