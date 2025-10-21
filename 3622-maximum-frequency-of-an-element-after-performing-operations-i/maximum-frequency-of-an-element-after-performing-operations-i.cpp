class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, int> mp;
        for(int it: nums)
            mp[it]++;
        int freq = 0, ans = 0;
        auto i = mp.begin(), j = mp.begin();
        int mini = i->first, maxi = prev(mp.end())->first;

        for(int it = mini; it <= maxi; it++){
            while(j != mp.end() && j->first <= it+k){
                freq += j->second;
                j++;
            }
            
            while(i != mp.end() && i->first < it-k){
                freq -= i->second;
                i++;
            }
            ans = max(ans, min(mp[it] + numOperations, freq));
        }
        return ans;
    }
};