from collections import deque

class Solution:
    def maximumInvitations(self, favorites):
        n = len(favorites)
        inDegree = [0] * n
        chainLengths = [0] * n
        visited = [False] * n

        # In-degree calculate karo
        for fav in favorites:
            inDegree[fav] += 1

        # Nodes with in-degree = 0 process karo
        q = deque()
        for i in range(n):
            if inDegree[i] == 0:
                q.append(i)

        while q:
            node = q.popleft()
            visited[node] = True

            next_node = favorites[node]
            chainLengths[next_node] = chainLengths[node] + 1
            inDegree[next_node] -= 1
            if inDegree[next_node] == 0:
                q.append(next_node)

        # Cycles detect aur process karo
        maxCycle = 0
        totalChains = 0
        for i in range(n):
            if not visited[i]:
                current = i
                cycleLength = 0
                while not visited[current]:
                    visited[current] = True
                    current = favorites[current]
                    cycleLength += 1

                # Cycle ka size check karo
                if cycleLength == 2:
                    totalChains += 2 + chainLengths[i] + chainLengths[favorites[i]]
                else:
                    maxCycle = max(maxCycle, cycleLength)

        return max(maxCycle, totalChains)