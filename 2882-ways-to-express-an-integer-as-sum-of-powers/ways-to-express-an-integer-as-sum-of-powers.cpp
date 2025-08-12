#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1000000007;
    vector<vector<int>> dp;

    int solve(int n, int x, int curr, int sum) {
        if (sum > n) return 0;
        if (sum == n) return 1;

        if (dp[curr][sum] != -1) return dp[curr][sum];

        long long power = 1;
        for (int i = 0; i < x; i++) {
            power *= curr;
            if (power > n) break;
        }
        if (power > n) return dp[curr][sum] = 0;

        int include = solve(n, x, curr + 1, sum + power) % MOD;
        int exclude = solve(n, x, curr + 1, sum) % MOD;

        return dp[curr][sum] = (include + exclude) % MOD;
    }

    int numberOfWays(int n, int x) {
        dp.assign(n + 2, vector<int>(n + 1, -1));
        return solve(n, x, 1, 0);
    }
};