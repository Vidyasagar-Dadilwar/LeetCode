class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& vis){
        vis[i][j] = true;
        for(auto& d: dirs){
            int x = i + d[0], y = j + d[1];
            if(x<0 || x>=heights.size() || y<0 || y>=heights[0].size() || vis[x][y] || heights[x][y] < heights[i][j])
                continue;
            dfs(x, y, heights, vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(), n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> p(m, vector<bool>(n, false)), a(m, vector<bool>(n, false));

        for (int j = 0; j < n; j++) dfs(0, j, heights, p);
        for (int i = 0; i < m; i++) dfs(i, 0, heights, p);

        for (int j = 0; j < n; j++) dfs(m-1, j, heights, a);
        for (int i = 0; i < m; i++) dfs(i, n-1, heights, a);

        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p[i][j] && a[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};