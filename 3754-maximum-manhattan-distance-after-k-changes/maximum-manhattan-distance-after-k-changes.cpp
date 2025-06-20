class Solution {
public:
    int maxDistance(string s, int k) {
        if(s.size() == 1)
            return 1;
        int l=0, u=0, ans = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'N')
                u++;
            else if(s[i] == 'S')
                u--;
            else if(s[i] == 'E')    
                l++;
            else
                l--;
            int t = abs(u) + abs(l);
            t = min(t + 2*k, i+1);
            ans = max(ans, t);
        }
        return ans;
    }
};