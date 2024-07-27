class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int inf = INT_MAX;

        vector<vector<int>> cost_matrix(26, vector<int>(26, inf));

        for (int i = 0; i < 26; ++i) {
            cost_matrix[i][i] = 0;
        }

        for (size_t idx = 0; idx < original.size(); ++idx) {
            int o = original[idx] - 'a';
            int c = changed[idx] - 'a';
            cost_matrix[o][c] = min(cost_matrix[o][c], cost[idx]);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (cost_matrix[i][k] < inf && cost_matrix[k][j] < inf) {
                        cost_matrix[i][j] = min(cost_matrix[i][j], cost_matrix[i][k] + cost_matrix[k][j]);
                    }
                }
            }
        }

        long long total_cost = 0;
        for (size_t i = 0; i < source.length(); ++i) {
            if (source[i] == target[i]) {
                continue;
            }
            int s = source[i] - 'a';
            int t = target[i] - 'a';
            if (cost_matrix[s][t] == inf) {
                return -1;
            }
            total_cost += cost_matrix[s][t];
        }
        return total_cost;
    }
};