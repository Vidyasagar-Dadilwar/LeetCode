class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colSum) {
        vector<vector<int>> ans(2, vector<int>(colSum.size(), 0));
        for(int j=0; j<colSum.size(); j++){
            if(colSum[j]==2){
                upper--;lower--;
                ans[0][j]=1;ans[1][j]=1;
            }
            if(upper<0 || lower<0) return {};
        }
        for(int j=0; j<colSum.size(); j++){
            if(colSum[j]==1){
                if(upper>0){
                    upper--;
                    ans[0][j]=1;
                }
                else{
                    lower--;
                    ans[1][j]=1;
                }
                if(lower<0) return {};
            }
        }
        if(lower==0 && upper==0) return ans;
        return {};
    }
};