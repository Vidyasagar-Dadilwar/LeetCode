class Solution {
public:
    int solve(string s, int i, int sign, int res){
        if(i == s.size() || !isdigit(s[i]))
            return res*sign;
        int digit = s[i]-'0';
        if(res > (INT_MAX-digit)/10)
            return (sign == 1) ? INT_MAX : INT_MIN;
        res = res*10 + digit;
        i++;
        return solve(s, i, sign, res);
    }
    int helper(string s, int i, int sign){
        while(s[i] == ' ')
            i++;
        if(i == s.size())
            return 0;
        if(s[i] == '-' || s[i] == '+'){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        return solve(s, i, sign, 0);
    }
    int myAtoi(string s) {
        int i=0, sign=1;
        return helper(s, i, sign);
    }
};