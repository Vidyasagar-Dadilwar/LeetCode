class Solution {
public:    
    vector<vector<int>> d = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    void dfs(vector<vector<char>>& grid, int x, int y, int n, int m){
        if(x>=n || x<0 || y>=m || y<0)
            return;
        grid[x][y] = '0';
        for(int i=0; i<4; i++){
            int new_x = x + d[i][0];
            int new_y = y + d[i][1];
            if(new_x>=n || new_x<0 || new_y>=m || new_y<0)
                continue;
            if(grid[new_x][new_y] == '0')
                continue;
            dfs(grid, new_x, new_y, n, m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    dfs(grid, i, j, n, m);
                    ans++;
                }
            }
        }
        return ans;
    }
};
