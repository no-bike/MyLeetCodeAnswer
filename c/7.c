class Solution:
    def magicTower(self, nums: List[int]) -> int:
        heap = []
        hp = 1
        ans = 0
        if sum(nums) < 0:
            return -1
        for num in nums:
            if num < 0:
                heapq.heappush(heap,num)
            hp += num
            while hp <= 0:
                hp -= heapq.heappop(heap)
                ans += 1
        return ans