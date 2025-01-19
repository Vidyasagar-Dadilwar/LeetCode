class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) 
            return 0;

        int n = heightMap.size(), m = heightMap[0].size();
        int ans = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    vis[i][j] = 1;
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int maxHeight = 0;

        while (!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            int h = f.first;
            int x = f.second.first, y = f.second.second;

            maxHeight = max(maxHeight, h);
            for (auto dir : directions) {
                int dx = x + dir.first;
                int dy = y + dir.second;

                if (dx >= 0 && dx < n && dy >= 0 && dy < m && !vis[dx][dy]) {
                    if (heightMap[dx][dy] < maxHeight) {
                        ans += maxHeight - heightMap[dx][dy];
                    }
                    pq.push({heightMap[dx][dy], {dx, dy}});
                    vis[dx][dy] = 1;
                }
            }
        }
        return ans;
    }
};