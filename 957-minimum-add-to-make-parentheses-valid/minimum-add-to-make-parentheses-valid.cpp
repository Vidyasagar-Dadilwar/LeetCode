class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>stk;
        int cnt=0;
        for(auto c: s){
            if(c=='('){
                stk.push(c);
                cnt++;
            }
            else if(c==')'){
                if(!stk.empty() && stk.top()=='('){
                    stk.pop();
                    cnt--;
                }
                else{
                    cnt++;
                }
            }
        }
        return cnt;
    }
};