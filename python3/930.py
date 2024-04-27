class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        flag = 0
        sumnum = sum(nums)
        ans = 0
        dp =[0]*(sumnum + 1)
        dp[0] = 1
        for num in nums:
            flag += num
            dp[flag] += 1
        if goal != 0:
            for i in range(goal,sumnum+1):
                ans += dp[i]*dp[i-goal]
        else:
            for i in range(0,sumnum+1):
                for j in range(1,dp[i]):
                    ans += j
        return ans