class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(auto g: guards)
            grid[g[0]][g[1]] = 1;
        for(auto w: walls)
            grid[w[0]][w[1]] = 2;
        
        for(auto g: guards){
            int i = g[0], j = g[1] - 1;
            while(j>=0 && grid[i][j]!=1 && grid[i][j]!=2){
                grid[i][j] = 3;
                j--;
            }
            i = g[0]-1, j = g[1];
            while(i>=0 && grid[i][j]!=1 && grid[i][j]!=2){
                grid[i][j] = 3;
                i--;
            }
            i = g[0], j = g[1]+1;
            while(j<n && grid[i][j]!=1 && grid[i][j]!=2){
                grid[i][j] = 3;
                j++;
            }
            i = g[0]+1, j = g[1];
            while(i<m && grid[i][j]!=1 && grid[i][j]!=2){
                grid[i][j] = 3;
                i++;
            }
        }
        int ans = 0;
        for(auto it: grid)
            ans += count(it.begin(), it.end(), 0);
        return ans;
    }
};