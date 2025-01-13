class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        unordered_map<int, int> mp;
        for(auto i: s){
            mp[i]++;
        }   
        int ans = 0;   
        for(auto it: mp){
            if(it.second <= 2)
                ans+=it.second;
            else if(it.second%2==0)
                ans+=2;
            else
                ans++;
        }
        return ans;
    }
};