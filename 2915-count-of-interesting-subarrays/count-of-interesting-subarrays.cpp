class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long cnt = 0, eq = 0;
        unordered_map<int, long long> mp;
        mp[0] = 1;
        for(auto i: nums){
            if(i % modulo == k)
                eq++;
            cnt += mp[((eq % modulo) - k + modulo) % modulo];
            mp[eq % modulo]++;
        }
        return cnt;
    }
};