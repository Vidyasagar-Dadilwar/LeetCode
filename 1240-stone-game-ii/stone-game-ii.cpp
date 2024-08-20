class Solution {
public:
    int n;
    int t[2][101][101];
    int solve(vector<int>&piles, int p, int i, int m){
        if(i>=n)
            return 0;
        if(t[p][i][m] != -1)
            return t[p][i][m];
        int res;
        if(p == 1){
            res = -1;
        }
        else{
            res = INT_MAX;
        }
        int stone = 0;
        for(int x = 1; x<=min(2*m, n-i); x++){
            stone += piles[i+x-1];
            res = (p == 1) ? max(res, stone + solve(piles, 0, i+x, max(m, x))) : min(res, solve(piles, 1, i+x, max(m, x)));
        }
        return t[p][i][m] = res;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(t, -1, sizeof(t));
        return solve(piles, 1, 0, 1);
    }
};