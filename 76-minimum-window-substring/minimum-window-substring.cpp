class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mp;
        for(auto c: t){
            mp[c]++;
        }
        int l=0, r=0, minLen=INT_MAX, start=0;
        int req=mp.size(), form=0;
        unordered_map<char, int>mppp;
        while(r<s.size()){
            mppp[s[r]]++;
            if(mp.count(s[r]) && mppp[s[r]]==mp[s[r]]){
                form++;
            }
            while(l<=r && form==req){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    start=l;
                }
                mppp[s[l]]--;
                if(mp.count(s[l]) && mppp[s[l]]<mp[s[l]]){
                    form--;
                }
                l++;
            }
            r++;
        }
        return (minLen==INT_MAX)?"" : s.substr(start, minLen);
    }
};