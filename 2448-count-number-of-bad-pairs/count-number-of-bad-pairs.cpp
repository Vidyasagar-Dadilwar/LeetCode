class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long, long long>mp;
        long long n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i] - i]++;
        }
        long long cnt = 0;
        for(auto [key, val]: mp){
            if(val > 1){
                cnt += val*(val - 1)/2;
            }
        }
        return  n * (n - 1) / 2 - cnt;
    }
};