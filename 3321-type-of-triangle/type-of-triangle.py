class Solution:
    def triangleType(self, nums: List[int]) -> str:
        a, b, c = nums
        maxi = max(nums)
        summ = sum(nums) - maxi
        if(maxi >= summ):
            return "none"
        elif(a==b==c):
            return "equilateral"
        elif(a==b or b==c or c==a):
            return "isosceles"
        else:
            return "scalene"
        