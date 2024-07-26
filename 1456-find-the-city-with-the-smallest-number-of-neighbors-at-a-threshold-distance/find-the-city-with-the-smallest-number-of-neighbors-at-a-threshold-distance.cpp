class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            mat[i][i] = 0;
        }

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            mat[u][v] = w;
            mat[v][u] = w;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (mat[i][k] < INT_MAX && mat[k][j] < INT_MAX) {
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }

        int minCount = INT_MAX;
        int resultCity = -1;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= minCount) {
                minCount = count;
                resultCity = i;
            }
        }
        return resultCity;
    }
};