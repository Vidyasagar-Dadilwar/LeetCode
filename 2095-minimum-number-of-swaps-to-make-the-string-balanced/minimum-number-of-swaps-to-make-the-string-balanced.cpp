class Solution {
public:
    int minSwaps(string s) {
        long o=0, c=0;
        int i=0, j=s.size()-1, cnt=0;
        for(auto i: s){
            if(i=='['){
                o++;
            }
            else if(i==']'){
                if(o==0){
                    cnt++;
                    o++;
                }
                else{
                    o--;
                }
            }
        }
        return cnt;
    }
};