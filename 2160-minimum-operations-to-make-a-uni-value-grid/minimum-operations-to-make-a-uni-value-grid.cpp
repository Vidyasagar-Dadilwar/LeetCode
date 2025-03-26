class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<int> tmp;
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[0].size(); j++)
                tmp.push_back(grid[i][j]);
        int n = tmp.size();
        sort(tmp.begin(), tmp.end());
        int t = tmp[n/2];
        int ans = 0;
        for(int i: tmp){
            if(i%x != t%x)
                return -1;
            ans += abs(t-i)/x;
        }
        return ans;
    }
};