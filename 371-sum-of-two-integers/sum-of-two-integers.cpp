class Solution {
public:
    int getSum(int a, int b) {
        while(a != 0){
            int c = a & b;
            b = a ^ b;
            a = c << 1;
        }
        return b;
    }
};