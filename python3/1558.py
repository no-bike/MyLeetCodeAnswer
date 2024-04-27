class Solution:
    def minOperations(self, nums: List[int]) -> int:
        count = 0
        maxnum = max(nums)
        count = maxnum.bit_length()
        count += sum(num.bit_count() for num in nums)
        return count - 1 if count > 0 else count