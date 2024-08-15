class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0, t=0, tt=0;
        for(int i: bills){
            int temp = i-5;
            if(i==5){
                f++;
            }
            else if(i==10){
                t++;
                if(f>0){
                    f--;
                }
                else{
                    return false;
                }
            }
            else if(i==20){
                tt++;
                if(f>0 && t>0){
                    f--;
                    t--;
                }
                else if(f>=3){
                    f-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};