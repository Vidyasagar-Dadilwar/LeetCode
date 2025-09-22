class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto it: nums)
            mp[it]++;
        int ans = 0, freq = 0;
        for(auto it: mp)
            freq = max(freq, it.second);
    
        for(auto it: mp){
            if(it.second == freq)
                ans += freq;
        }
        return ans;
    }
};