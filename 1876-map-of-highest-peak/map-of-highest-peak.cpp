class Solution {
public:
    vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j] == 1){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            for(auto d: direction){
                int i = curr.first + d.first;
                int j = curr.second + d.second;

                if(i>=0 && i<n && j>=0 && j<m && ans[i][j] == -1){
                    ans[i][j] = ans[curr.first][curr.second] + 1;
                    q.push({i, j});
                }
            }
        }

        return ans;
    }
};