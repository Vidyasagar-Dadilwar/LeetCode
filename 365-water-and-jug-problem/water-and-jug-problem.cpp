class Solution {
public:
    int gcd(int x, int y){
        while(y != 0){
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
    bool canMeasureWater(int x, int y, int target) {
        if(target > x+y){
            return false;
        }
        if(target == 0){
            return true;
        }
        int xy = gcd(x, y);
        return target % xy == 0;
    }
};