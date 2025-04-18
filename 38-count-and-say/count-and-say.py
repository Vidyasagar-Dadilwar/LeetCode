class Solution:
    def rle(self, s):
        cnt = 0
        curr = s[0]
        ans = ""
        for c in s:
            if(c == curr):
                cnt += 1
            else:
                ans += str(cnt) + curr
                curr = c
                cnt = 1
        ans += str(cnt) + curr
        return ans

    def countAndSay(self, n: int) -> str:
        curr = "1"
        for i in range(1, n):
            curr = self.rle(curr)
        return curr