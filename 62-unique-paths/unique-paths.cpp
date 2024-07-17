class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> visited(m, vector<int>(n, -1));
        visited[0][0]=1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0)
                    continue;
                visited[i][j] = i>0?visited[i-1][j]:0;
                visited[i][j] += j>0?visited[i][j-1]:0;
            }
        }
        return visited[m-1][n-1];
    }
};