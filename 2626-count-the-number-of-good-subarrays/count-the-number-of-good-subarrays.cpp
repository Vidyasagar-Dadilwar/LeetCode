class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size();
        long long ans = 0, cnt = 0;
        unordered_map<long long, long long> mp;
        while(l<n){
            while(r<n && cnt < k){
                mp[nums[r]]++;
                if(mp[nums[r]] >= 2){
                    cnt += mp[nums[r]] - 1;
                }
                r++;
            }
            if(cnt >= k)
                ans += n-r+1;
            mp[nums[l]]--;
            if(mp[nums[l]] > 0)
                cnt -= mp[nums[l]];
            l++;
        }
        return ans;
    }
};