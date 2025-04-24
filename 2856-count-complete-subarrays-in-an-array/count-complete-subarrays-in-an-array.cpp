class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int total = st.size();
        int l = 0, cnt = 0, r = 0, n = st.size();
        while(r < nums.size()){
            mp[nums[r]]++;
            while(mp.size() == n){
                cnt += nums.size() - r;
                mp[nums[l]]--;
                if(!mp[nums[l]])
                    mp.erase(nums[l]);
                l++;
            }
            r++;
        }
        return cnt;
    }
};