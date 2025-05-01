class Solution:
    def maxTaskAssign(self, tasks, workers, pills, strength):
        n, m = len(tasks), len(workers)
        tasks.sort()
        workers.sort()

        def solve(mid):
            p = pills
            ws = SortedList(workers[m - mid :])
            for i in range(mid - 1, -1, -1):
                if ws[-1] >= tasks[i]:
                    ws.pop()
                else:
                    if p == 0:
                        return False
                    rep = ws.bisect_left(tasks[i] - strength)
                    if rep == len(ws):
                        return False
                    p -= 1
                    ws.pop(rep)
            return True

        l, r, ans = 1, min(m, n), 0
        while l <= r:
            mid = (l + r) // 2
            if solve(mid):
                ans = mid
                l = mid + 1
            else:
                r = mid - 1
        return ans