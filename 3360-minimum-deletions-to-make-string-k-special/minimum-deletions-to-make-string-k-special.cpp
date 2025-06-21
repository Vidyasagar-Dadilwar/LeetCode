class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> mp;
        for(auto it: word)
            mp[it]++;
        int ans = INT_MAX;
        for(auto x: mp){
            int del = 0;
            for(auto y: mp){
                if(y.second < x.second)
                    del += y.second;
                else if(y.second > x.second+k)
                    del += y.second - (x.second+k);
            }
            ans = min(ans, del);
        }
        return ans;
    }
};