class Solution {
    public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> ans(100);
        int cnt = 0;
        for (int i = 0; i < dominoes.size(); i++) {
            int a = dominoes[i][0], b = dominoes[i][1];
            int tmp = min(a, b)*10 + max(a,b);
            cnt += ans[tmp];
            ans[tmp]++;
        }
        return cnt;
    }
};