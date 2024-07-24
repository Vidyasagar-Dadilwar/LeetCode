class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, n=s.size();
        unordered_map<char, int>mp;
        int maxLen=0;
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