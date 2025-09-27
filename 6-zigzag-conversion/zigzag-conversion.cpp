class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) 
            return s;

        string ans = "";
        int k = 2 * numRows - 2; 

        for (int cnt = 0; cnt < numRows; cnt++) {
            int i = cnt;
            while (i < s.size()) {
                ans += s[i]; 
                int step = (k - 2 * cnt); 
                int step2 = (k - step);   
                if (step > 0 && step < k && i + step < s.size())
                    ans += s[i + step];
                i += k; 
            }
        }
        return ans;
    }
};