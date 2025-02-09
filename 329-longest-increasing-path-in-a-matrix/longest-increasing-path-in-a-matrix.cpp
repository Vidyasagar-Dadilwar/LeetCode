class Solution {
public:
    int m, n;
    int dfs(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if(dp[i][j]!=-1) 
            return dp[i][j];
        
        int longest = 1;
        if (i > 0 && mat[i - 1][j] > mat[i][j]) { 
            longest = max(longest, 1 + dfs(i - 1, j, mat, dp));
        }
        if (j < n - 1 && mat[i][j + 1] > mat[i][j]) {
            longest = max(longest, 1 + dfs(i, j + 1, mat, dp));
        }
        if (i < m - 1 && mat[i + 1][j] > mat[i][j]) { 
            longest = max(longest, 1 + dfs(i + 1, j, mat, dp));
        }
        if (j > 0 && mat[i][j - 1] > mat[i][j]) {
            longest = max(longest, 1 + dfs(i, j - 1, mat, dp));
        }

        return dp[i][j] = longest;
    }

    int longestIncreasingPath(vector<vector<int>>& mat) {
        int ans = -1;
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int res = dfs(i, j, mat, dp);
                ans = max(res, ans);
            }
        }

        return ans;
    }
};