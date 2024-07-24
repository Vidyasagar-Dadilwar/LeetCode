class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxLen=0;
        int n=s.size();
        unordered_map<int,int>mp;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]==2){
                mp[s[l]]--;
                l++;
            }
            maxLen=max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};