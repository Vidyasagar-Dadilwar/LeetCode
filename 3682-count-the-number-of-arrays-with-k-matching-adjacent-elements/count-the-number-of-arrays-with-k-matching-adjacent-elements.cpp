class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modpow(long long base, long long exp, long long mod) {
        return exp == 0 ? 1 :
               (exp % 2 == 0 ? modpow((base * base) % mod, exp / 2, mod) :
               (base * modpow(base, exp - 1, mod)) % mod);
    }

    long long modinv(long long a, long long mod) {
        return modpow(a, mod - 2, mod);
    }

    long long nCk_mod(long long n, long long k) {
        if (k < 0 || k > n) return 0;
        static vector<long long> fact(1, 1), inv_fact(1, 1);

        if (fact.size() <= n) {
            int old_size = fact.size();
            fact.resize(n + 1);
            inv_fact.resize(n + 1);
            for (int i = old_size; i <= n; ++i) {
                fact[i] = fact[i - 1] * i % MOD;
                inv_fact[i] = modinv(fact[i], MOD);
            }
        }

        return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        long long c = nCk_mod(n - 1, k);
        long long p = modpow(m - 1, n - 1 - k, MOD);
        return (1LL * m * c % MOD * p % MOD);
    }
};