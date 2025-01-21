class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long ans = LONG_LONG_MAX;
        long long fsum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long ssum = 0;
        for(int i=0; i<n; i++){
            fsum -= grid[0][i];
            ans = min(ans, max(fsum, ssum));
            ssum += grid[1][i];
        }
        return ans;
    }
};