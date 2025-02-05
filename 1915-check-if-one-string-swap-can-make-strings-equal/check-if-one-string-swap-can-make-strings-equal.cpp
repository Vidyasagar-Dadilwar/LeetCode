class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int t1=0,t2=0, cnt = 0;
        if(s1 == s2) return true;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i] && t1 == 0){
                t1 = i;
                cnt++;
            }
            else if(s1[i] != s2[i] && t1 != 0){
                t2 = i;
                cnt++;
            }
            else if(s1[i] != s2[i]) cnt++;
        }
        if(cnt == 2 && (s1[t1] == s2[t2]) && (s2[t1] == s1[t2]))
            return true;
        return false;
    }
};