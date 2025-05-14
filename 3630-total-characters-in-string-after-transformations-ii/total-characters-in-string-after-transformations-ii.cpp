class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> matrix_mul(const vector<vector<int>> &a, const vector<vector<int>> &b) {
        int n = a.size();
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int k = 0; k < n; k++)
                for (int j = 0; j < n; j++)
                    res[i][j] = (res[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
        return res;
    }

    vector<vector<int>> power(vector<vector<int>> base, int exp) {
        int n = base.size();
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            res[i][i] = 1;

        while (exp) {
            if (exp % 2 == 1)
                res = matrix_mul(res, base);
            base = matrix_mul(base, base);
            exp /= 2;
        }
        return res;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int n = 26;
        vector<vector<int>> mat(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                int tmp = (i + j) % n;
                mat[i][tmp] = (mat[i][tmp] + 1) % MOD;
            }
        }

        vector<vector<int>> mat_exp = power(mat, t);
        vector<int> freq(n, 0);
        for (char c : s)
            freq[c - 'a']++;

        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i] = (res[i] + 1LL * mat_exp[j][i] * freq[j]) % MOD;
            }
        }

        int ans = 0;
        for (int it : res)
            ans = (ans + it) % MOD;

        return ans;
    }
};