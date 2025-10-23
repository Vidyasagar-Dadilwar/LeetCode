class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2){
            string tmp = "";
            for(int i=0; i<s.size()-1; i++){
                tmp += to_string(((int)s[i] + (int)s[i+1])%10);
            }
            s = tmp;
        }
        return s[0] == s[1];
    }
};