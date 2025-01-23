class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> r(n, 0), c(m, 0);
        int total = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    r[i]++;
                    c[j]++;
                    total++;
                }
            }
        }
        int single = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && r[i] == 1 && c[j] == 1) {
                    single++;
                }
            }
        }
        
        return total - single;
    }
};