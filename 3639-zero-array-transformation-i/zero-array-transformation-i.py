class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        n = len(nums)
        diff = [0] * n
        
        for it in queries:
            l, h = it
            diff[l] -= 1
            if(h+1 < n):
                diff[h+1] += 1
        
        for i in range(1, n):
            diff[i] = diff[i] + diff[i-1]
        
        for i in range(n):
            if(nums[i] + diff[i] > 0):
                return False
        
        return True