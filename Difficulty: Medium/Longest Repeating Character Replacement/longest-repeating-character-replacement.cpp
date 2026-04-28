class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int l=0, freq=0, maxi=0;
        vector<int> arr(26, 0);
        for(int r=0; r<s.size(); r++){
            arr[s[r]-'A']++;
            freq = max(freq, arr[s[r]-'A']);
            while(r-l+1-freq > k){
                arr[s[l]-'A']--;
                l++;
            }
            maxi = max(maxi, r-l+1);
        }
        return maxi;
    }
};