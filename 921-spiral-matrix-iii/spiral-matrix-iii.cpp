class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<vector<int>> res;
        int steps = 1;
        int r = rStart, c = cStart;
        int d = 0; // direction index

        while (res.size() < rows * cols) {
            for (int j = 0; j < 2; ++j) {
                for (int i = 0; i < steps; ++i) {
                    if (0 <= r && r < rows && 0 <= c && c < cols) {
                        res.push_back({r, c});
                    }
                    r += dir[d][0];
                    c += dir[d][1];
                }
                d = (d + 1) % 4; 
            }
            steps++;
        }
        return res;
    }
};