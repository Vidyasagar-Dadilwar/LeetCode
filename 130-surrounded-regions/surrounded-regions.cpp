class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        int m = board.size(), n = board[0].size();
        visited[i][j] = true;

        for (int d = 0; d < 4; ++d) {
            int ni = i + dx[d];
            int nj = j + dy[d];

            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                board[ni][nj] == 'O' && !visited[ni][nj]) {
                dfs(ni, nj, board, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O' && !visited[0][j])
                dfs(0, j, board, visited);
            if (board[m - 1][j] == 'O' && !visited[m - 1][j])
                dfs(m - 1, j, board, visited);
        }

        for (int i = 1; i < m - 1; ++i) {
            if (board[i][0] == 'O' && !visited[i][0])
                dfs(i, 0, board, visited);
            if (board[i][n - 1] == 'O' && !visited[i][n - 1])
                dfs(i, n - 1, board, visited);
        }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
    }
};