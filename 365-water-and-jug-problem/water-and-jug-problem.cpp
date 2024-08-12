class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target > x+y){
            return false;
        }
        if(target == 0){
            return true;
        }
        int temp = __gcd(x, y);
        return target % temp == 0;
    }
};