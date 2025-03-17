class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i: nums)
            mp[i]++;
        for(auto it: mp)
            if(it.second % 2 == 1) return false;
        return true;
    }
};