class Solution {
public:
    int minLength(string s) {
        stack<char>stk;
        for(auto c: s){
            stk.push(c);
            while(stk.size() > 1){
                char sec = stk.top();
                stk.pop();
                char fst = stk.top();
                if((fst == 'A' && sec == 'B') || (fst == 'C' && sec == 'D')){
                    stk.pop();
                }
                else{
                    stk.push(sec);
                    break;
                }
            }
        }
        return stk.size();
    }
};