class Solution {
public:
    bool isInteger(double num) {
        return fabs(num - round(num)) < 1e-10;
    }
    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        double res = (log(n)/log(3));
        return isInteger(res);
    }   
};