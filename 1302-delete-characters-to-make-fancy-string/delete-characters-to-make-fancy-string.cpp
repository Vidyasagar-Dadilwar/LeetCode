class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string ans = "";
        for(int i=0; i<n; i++){
            if(i<n-2){
                if(s[i]==s[i+1] && s[i+1]==s[i+2]){
                    continue;
                }
                else{
                    ans += s[i];
                }
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};