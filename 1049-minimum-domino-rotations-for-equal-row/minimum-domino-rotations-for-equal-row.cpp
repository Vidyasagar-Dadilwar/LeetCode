class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = INT_MAX;
        for (int j = 1; j <= 6; ++j) {
            bool flag = true;
            int t = 0, b = 0;
            for (int i = 0; i < tops.size(); ++i) {
                if (tops[i] != j && bottoms[i] != j) {
                    flag = false;
                    break;
                }
                if (tops[i] != j) 
                    t++;
                if (bottoms[i] != j) 
                    b++;
            }
            if (flag)
                res = min(res, min(t, b));
        }
        return res == INT_MAX ? -1 : res;
    }
};