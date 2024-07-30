class Solution {
public:
    int minimumDeletions(string s) {
        int cnt=0, bcnt=0;
        for(auto i: s){
            if(i == 'b'){
                bcnt++;
            }
            else if(bcnt > 0){
                bcnt--;
                cnt++;
            }
        }
        return cnt;
    }
};