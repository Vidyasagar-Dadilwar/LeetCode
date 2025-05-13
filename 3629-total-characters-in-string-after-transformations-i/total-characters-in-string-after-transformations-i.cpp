class Solution {
public:
    const int MOD = 1e9 + 7; 
    int lengthAfterTransformations(const string& s, int t) {
        vector<long long> freq(26, 0); 
        for (char c : s) {
            freq[c - 'a']++;
        }

        while(t--) {
            vector<long long> newFreq(26, 0);  
            for (int j = 0; j < 26; j++) {
                if (freq[j] > 0) {
                    if (j == 25) { 
                        newFreq[0] = (newFreq[0] + freq[j]) % MOD;
                        newFreq[1] = (newFreq[1] + freq[j]) % MOD;
                    } 
                    else {
                        newFreq[j + 1] = (newFreq[j + 1] + freq[j]) % MOD; 
                    }
                }
            }
            freq = newFreq;
        }

        long long ans = 0;  
        for (long long count : freq) {
            ans = (ans + count) % MOD;
        }

        return ans;
    }
};