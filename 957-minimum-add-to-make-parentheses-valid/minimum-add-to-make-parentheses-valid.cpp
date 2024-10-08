class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>stk;
        int cnt=0;
        for(auto i: s){
            if(i=='('){
                stk.push(i);
                cnt++;
            }
            else if(i==')'){
                if(!stk.empty() && stk.top() == '('){
                    stk.pop();
                    cnt--;
                }
                else
                    cnt++;
            }
        }
        return cnt;
    }
};