class Solution:
    def solve(self, n, current, l):
        if current > n:
            return
        l.append(current)
        for i in range(10):
            if current * 10 + i > n:
                return
            self.solve(n, current * 10 + i, l)

    def lexicalOrder(self, n: int) -> List[int]:
        l = []
        for i in range(1, 10):
            if i > n:
                break
            self.solve(n, i, l)
        return l