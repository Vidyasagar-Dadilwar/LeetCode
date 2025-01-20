class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int ans = 0;
        int row=0, col=0;
        int n = mat.size(), m = mat[0].size();
        vector<int> rows(n, 0);
        vector<int> cols(m, 0);
        map<int, pair<int, int>> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[mat[i][j]] = {i, j};
            }
        }
        for(int i=0; i<arr.size(); i++){
            if(mp.find(arr[i]) != mp.end()){
                row = mp[arr[i]].first;
                col = mp[arr[i]].second;
            }
            rows[row]++;
            cols[col]++;
            if(rows[row]==m || cols[col]==n){
                return i;
            }
        }
        return -1;
    }
};