class Solution {
public:
    bool checkMagicSquare(const vector<vector<int>>& grid, int r, int c) {
        unordered_set<int> visited;
        int targetSum = 0;

        for (int i = 0; i < 3; i++) {
            int rowSum = 0;
            for (int j = 0; j < 3; j++) {
                int val = grid[r + i][c + j];
                if (val < 1 || val > 9 || visited.count(val)) {
                    return false;
                }
                visited.insert(val);
                rowSum += val;
            }
            if (i == 0) {
                targetSum = rowSum;
            } else if (rowSum != targetSum) {
                return false;
            }
        }

        for (int j = 0; j < 3; j++) {
            int colSum = 0;
            for (int i = 0; i < 3; i++) {
                colSum += grid[r + i][c + j];
            }
            if (colSum != targetSum) {
                return false;
            }
        }

        int d1 = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
        int d2 = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];

        if (d1 != targetSum || d2 != targetSum) {
            return false;
        }

        return true;
    }

    int numMagicSquaresInside(const vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (checkMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};