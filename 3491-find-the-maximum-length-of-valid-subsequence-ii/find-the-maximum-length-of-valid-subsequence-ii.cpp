class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int ans = 2;
        for(int i=0; i<n; i++){
            int curr = nums[i]%k;
            for(int j=0; j<k; j++){
                dp[curr][j] = max(dp[curr][j], dp[j][curr] + 1);
                ans = max(ans, dp[curr][j]);
            }
        }
        return ans;
    }
};