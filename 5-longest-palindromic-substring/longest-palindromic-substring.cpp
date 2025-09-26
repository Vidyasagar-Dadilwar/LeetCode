class Solution {
public:
    int n=0, len=0, start=0;
    void expand(int l, int r, string s){
        while(l >= 0 && r < n && s[l] == s[r])
            l--, r++;
        if(r-l-1 > len){
            len = r-l-1;
            start = l+1;
        }
    }
    string longestPalindrome(string s) {
        n = s.size();
        if(n <= 1) return s;

        for(int i=0; i<n; i++){
            expand(i, i, s);
            expand(i, i+1, s);
        }
        return s.substr(start, len);
    }
};