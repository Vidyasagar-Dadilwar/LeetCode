class Solution {
public:
    int numberOfSubstrings(string s) {
        int l, r, a, b, c, ans;
        l=r=a=b=c=ans=0;
        int n = s.size();
        while(r < n){
            if(s[r] == 'a') a++;
            if(s[r] == 'b') b++;
            if(s[r] == 'c') c++;

            while(a && b && c){
                ans += n-r;
                if(s[l] == 'a') a--;
                if(s[l] == 'b') b--;
                if(s[l] == 'c') c--;
                l++;
            }
            r++;
        }
        return ans;
    }
};