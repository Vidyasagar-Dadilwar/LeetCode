class Solution {
public:
    int solve(string& s, int i, int sign, int result){
        if(i==s.size() || !isdigit(s[i])){
            return result*sign;
        }
        int digit=s[i]-'0';
        if (result > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        result=result*10 + digit;
        i++;
        return solve(s, i, sign, result);
    }
    int helper(string &s, int i, int sign){
        while(i<s.size() && s[i]==' '){
            i++;
        }
        // base condition
        if(i==s.size()){
            return 0;
        }
        // sign determination
        if(s[i]=='-' || s[i]=='+'){
            sign=(s[i]=='-')?-1:1;
            i++;
        }
        return solve(s, i, sign, 0);
    }
    int myAtoi(string s) {
        int ind=0, sign=1;
        return helper(s, ind, sign);
    }
};