class Solution {
public:
    const int MOD = 1e9 + 7;
    const int MAX_K = 14;
    vector<vector<int>> computeCombinations(int n) {
        vector<vector<int>> C(n + 1, vector<int>(MAX_K + 1, 0));
        for (int i = 0; i <= n; ++i) {
            C[i][0] = 1;
            for (int j = 1; j <= min(i, MAX_K); ++j) {
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
            }
        }
        return C;
    }
    int idealArrays(int n, int maxValue) {
        auto C = computeCombinations(n);
        vector<vector<long long>> dp(maxValue + 1, vector<long long>(MAX_K + 1, 0));
        for (int i = 1; i <= maxValue; ++i) {
            dp[i][1] = 1;
        }
        for (int len = 2; len <= MAX_K; ++len) {
            for (int i = 1; i <= maxValue; ++i) {
                for (int j = i * 2; j <= maxValue; j += i) {
                    dp[j][len] = (dp[j][len] + dp[i][len - 1]) % MOD;
                }
            }
        }
        long long res = 0;
        for (int i = 1; i <= maxValue; ++i) {
            for (int len = 1; len <= MAX_K; ++len) {
                res = (res + dp[i][len] * 1LL * C[n - 1][len - 1]) % MOD;
            }
        }    
        return (int)res;
    }
};