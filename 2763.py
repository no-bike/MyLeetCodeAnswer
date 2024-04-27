class Solution:
    def minIncrements(self, n: int, cost: List[int]) -> int:
        ans = 0
        for i in range(n-2,0,-2):
            ans += abs(cost[i] - cost[i+1])
            cost[i//2] += max(cost[i],cost[i+1])
        return ans