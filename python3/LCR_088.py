class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        pre = cur = 0
        for i in range(1, len(cost)):
            pre, cur = cur, min(pre + cost[i - 1], cur + cost[i])
        return cur