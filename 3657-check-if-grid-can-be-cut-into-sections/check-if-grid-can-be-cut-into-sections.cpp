class Solution {
public:
    bool solve(vector<vector<int>>& intv){
        sort(intv.begin(), intv.end());
        int ans = 0;
        int maxi = intv[0][1];
        for(auto& i: intv){
            int s = i[0], e = i[1];
            if(maxi <= s)
                ans++;
            maxi = max(maxi, e);
        }
        return ans >= 2;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x, y;
        for(auto& i: rectangles){
            x.push_back({i[0], i[2]});
            y.push_back({i[1], i[3]});
        }
        return solve(x) || solve(y);
    }
};