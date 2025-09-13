class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;
        for(auto it: s)
            mp[it]++;
        int maxc = 0, maxv = 0;
        for(auto [it, pp]: mp){
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u')
                maxv = max(maxv, pp);
            else
                maxc = max(maxc, pp);
        }
        return maxv + maxc;
    }
};