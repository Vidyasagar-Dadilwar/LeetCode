class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == numeric_limits<int>::min() && divisor == -1)
            return numeric_limits<int>::max();
        return  dividend / divisor;
    }
};