class Solution {
public:
    string decimalToTernary(int n) {
        if (n == 0) return "0";
        string ternary = "";
        while (n > 0) {
            ternary = to_string(n % 3) + ternary; 
            n /= 3;
        }
        return ternary;
    }

    bool checkPowersOfThree(int n) {
        string t = decimalToTernary(n);
        for(auto i: t){
            if(i == '2')
                return false;
        }
        return true;
    }
};