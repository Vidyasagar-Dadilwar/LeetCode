class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0, time = 0;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        
        while(!q.empty() && fresh > 0){
            int size = q.size();
            while(size--){
                auto [i, j] = q.front(); q.pop();
                for(auto dir : dirs){
                    int x = i + dir[0], y = j + dir[1];
                    if(x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x, y});
                        fresh--;
                    }
                }
            }
            time++;
        }        
        return fresh == 0 ? time : -1;
    }
};