class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        vector<int> mark(n, 0);
        for(int i=0; i<n; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                mark[i] = 1;
                for(int j = i; j>=0; j--){
                    if(mark[j] == 0){
                        mark[j] = 1;
                        break;
                    }
                }
            }
        }
        string ans = "";
        for(int i=0; i<n; i++){
            if(mark[i] == 0)
                ans += s[i];
        }
        return ans;
    }
};