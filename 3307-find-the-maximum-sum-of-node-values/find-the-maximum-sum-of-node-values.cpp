class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        long long ans = 0, tmp = INT_MAX, cnt = 0;

        for(int i=0; i<n; i++){
            if(nums[i] < (nums[i] ^ k)){
                cnt++;
                ans += (nums[i] ^ k);
                tmp = min(tmp, (long long)(nums[i] ^ k) - nums[i]);
            }
            else{
                ans += nums[i];
                tmp = min(tmp, (nums[i] - ((long long)nums[i] ^ k)));
            }
        }
        if(cnt % 2)
            ans -= tmp;
        return ans;
    }
};