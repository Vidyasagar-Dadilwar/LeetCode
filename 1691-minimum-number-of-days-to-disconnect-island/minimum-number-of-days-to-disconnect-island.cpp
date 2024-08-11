class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || visited[i][j] || grid[i][j]==0){
            return;
        }
        visited[i][j]=1;

        dfs(grid, i+1, j, visited);
        dfs(grid, i-1, j, visited);
        dfs(grid, i, j+1, visited);
        dfs(grid, i, j-1, visited);
    }
    int countIslands(vector<vector<int>>& grid){
        int islands=0;
        int row=grid.size(), col=grid[0].size();
        
        vector<vector<int>> visited(row,vector<int>(col));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    dfs(grid, i, j, visited);
                    islands++;
                }
            }
        }
        return islands;
    }
    int minDays(vector<vector<int>>& grid) {
        int row=grid.size(), col=grid[0].size();
        int islands = countIslands(grid);

        if(islands==0 || islands>1)
            return 0;
        else{
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    if(grid[i][j]==1){
                        grid[i][j]=0;
                        if(countIslands(grid)>1 || countIslands(grid)==0){
                            return 1;
                        }
                        grid[i][j]=1;
                    }
                }
            }
        }
        return 2;
    }
};