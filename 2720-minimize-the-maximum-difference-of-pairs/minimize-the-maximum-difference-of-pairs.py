class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        n = len(nums)
        def solve(nums, m):
            i, cnt = 1, 0
            while(i<n):
                if(nums[i]-nums[i-1] <= m):
                    cnt += 1
                    i += 2
                else:
                    i += 1
            return cnt
            
        nums.sort()
        l, h = 0, nums[n-1] - nums[0]

        while(l<=h):
            m = l + (h - l)//2
            if(solve(nums, m) >= p):
                h = m - 1
            else:
                l = m + 1
        return l