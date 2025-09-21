class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> x, y;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    x.insert(i), y.insert(j);
                }
            }
        }
        for(auto it1: x){
            for(int j=0; j<matrix[0].size(); j++){
                matrix[it1][j] = 0;
            }
        }
        for(auto it1: y){
            for(int j=0; j<matrix.size(); j++){
                matrix[j][it1] = 0;
            }
        }
    }
};