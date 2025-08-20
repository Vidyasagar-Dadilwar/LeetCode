class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int cnt = 0;
        for(int i=1; i<mat.size(); i++){
            for(int j=1; j<mat[0].size(); j++){
                if(mat[i][j] == 1){
                    mat[i][j] = min({mat[i-1][j], mat[i][j-1], mat[i-1][j-1]})+1;
                }
            }
        }
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat[0].size(); j++)
                cnt += mat[i][j];
        
        return cnt;
    }
};