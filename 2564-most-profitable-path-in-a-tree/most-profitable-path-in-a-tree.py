class Solution:
    def mostProfitablePath(self, edges: List[List[int]], bob: int, amt: List[int]) -> int:
        graph = {i: [] for i in range(len(amt))}
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        bp = [-1] * len(amt)
        path = []

        def fillbp(node, parent):
            if node == 0:
                return True
            for x in graph[node]:
                if x != parent:
                    path.append(node)
                    if fillbp(x, node):
                        return True
                    path.pop()

        fillbp(bob, -1)
        for i, node in enumerate(path):
            bp[node] = i
        
        def solve(node, parent, curr, time):
            if bp[node] == -1 or bp[node] > time:
                curr += amt[node]
            elif bp[node] == time:
                curr += amt[node] // 2
            return curr if len(graph[node]) == 1 and node != 0 else max(solve(x, node, curr, time + 1) for x in graph[node] if x != parent)

        return solve(0, -1, 0, 0)