class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s; // edge case

        string ans = "";
        int k = 2 * numRows - 2; // cycle length

        for (int cnt = 0; cnt < numRows; cnt++) {
            int i = cnt;
            while (i < s.size()) {
                ans += s[i]; // main vertical char

                int step = (k - 2 * cnt); // diagonal step for middle rows
                int step2 = (k - step);   // complementary step

                // diagonal char only if it's not first/last row
                if (step > 0 && step < k && i + step < s.size())
                    ans += s[i + step];

                i += k; // jump to next cycle
            }
        }
        return ans;
    }
};