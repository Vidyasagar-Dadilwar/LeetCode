class Solution {
public:
    int solve(int ind, int sz, int ans, string s, int k){
        if(ind < 0)
            return sz;
        if(s[ind] == '0')
            return solve(ind-1, sz+1, ans, s, k);
        else{
            if(pow(2, sz) + ans > k)
                return solve(ind-1, sz, ans, s, k);
            else
                return solve(ind-1, sz+1, (int)pow(2, sz)+ans, s, k);
        }
    }
    int longestSubsequence(string s, int k) {
        return solve(s.size()-1, 0, 0, s, k);
    }
};