class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        ans = 0
        def is_distinct(arr):
            return len(arr) == len(set(arr))
            
        while not is_distinct(nums):
            nums = nums[3:]
            ans += 1
        
        return ans
          