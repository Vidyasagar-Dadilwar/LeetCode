class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        o, maxi = 0, 0
        for i in nums:
            if(i != 0):
                o += 1
                maxi = max(maxi, o)
            else:
                o = 0
        return maxi