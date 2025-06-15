class Solution {
public:
    int toNum(const vector<int>& arr) {
        int n = 0;
        for (int it : arr)
            n = n * 10 + it;
        return n;
    }

    int maxDiff(int num) {
        vector<int> digits;
        int temp = num;

        string s = to_string(temp);
        for (char c : s) {
            digits.push_back(c - '0');
        }

        vector<int> maxDigits = digits;
        for (int i = 0; i < digits.size(); i++) {
            if (digits[i] != 9) {
                int x = digits[i];
                for (int& d : maxDigits) {
                    if (d == x) 
                        d = 9;
                }
                break;
            }
        }

        vector<int> minDigits = digits;
        if(digits[0] != 1){
            int x = digits[0];
            for(auto& it: minDigits){
                if(it == x)
                    it = 1;
            }
        }
        else{
            for (int i = 1; i < digits.size(); i++) {
            if (digits[i] != 1 && digits[i] != 0) {
                int x = digits[i];
                for (int& d : minDigits) {
                    if (d == x) 
                        d = 0;
                }

                break;
            }
        }
        }

        int maxi = toNum(maxDigits), mini = toNum(minDigits);

        return maxi - mini;
    }
};