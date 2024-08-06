class Solution {
public:
    int minimumPushes(string word) {
        vector<int>dp(26,0);
        for(auto s: word)
            dp[s-'a']++;
        int k=0, ans=0;
        sort(dp.begin(), dp.end(), greater<int>());
        for(int i=0; i<26; i++){
            if(i%8 == 0)
                k++;
            ans += k*dp[i];
        }
        return ans;
    }
};