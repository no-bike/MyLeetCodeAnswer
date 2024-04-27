class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums)>2:
            dp = [nums[0],nums[1],nums[0]+nums[2]]
            for i in range(3,len(nums)):
                dp.append(nums[i]+ max(dp[i-2],dp[i-3]))
            return dp[-1] if dp[-1]>dp[-2] else dp[-2]
        elif len(nums) is 1:
            return nums[0]
        elif len(nums) is 2:
            return max(nums[0],nums[1])