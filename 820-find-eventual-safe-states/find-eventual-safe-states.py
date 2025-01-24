from functools import lru_cache
from typing import List
class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        res = []
        @lru_cache(None)
        def dfs(i):
            visiting.add(i)            
            for neighbor in graph[i]:
                if neighbor in visiting or not dfs(neighbor): 
                    visiting.remove(i)  
                    return False
            visiting.remove(i)
            return True
        visiting = set()  
        for i in range(n):
            if dfs(i): 
                res.append(i)
        return res