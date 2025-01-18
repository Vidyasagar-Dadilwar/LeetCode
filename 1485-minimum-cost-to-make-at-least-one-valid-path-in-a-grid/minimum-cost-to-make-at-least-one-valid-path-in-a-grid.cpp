class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> minCost(n, vector<int>(m, INT_MAX));
        vector<vector<int>> dir = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        deque<pair<int, int>> q;
        q.push_back({0, 0});
        minCost[0][0] = 0;
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop_front();
            for(int k=0; k<4; k++){
                int newRow = row + dir[k][0];
                int newCol = col + dir[k][1];
                int cost = (grid[row][col] == k+1) ? 0 : 1;

                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m &&
                    minCost[row][col] + cost < minCost[newRow][newCol]){
                        minCost[newRow][newCol] = minCost[row][col] + cost;
                        if(cost == 1){
                            q.push_back({newRow, newCol});
                        }
                        else{
                            q.push_front({newRow, newCol});
                        }
                }
            }
        }
        return minCost[n-1][m-1];
    }
};