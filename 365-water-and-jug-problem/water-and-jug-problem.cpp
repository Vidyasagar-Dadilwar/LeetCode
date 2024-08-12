class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
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