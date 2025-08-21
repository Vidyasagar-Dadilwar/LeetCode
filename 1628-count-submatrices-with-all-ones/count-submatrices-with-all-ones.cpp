class Solution {
public:
    int find(vector<vector<int>>&mat,int x,int y){ 
        int cnt=0, n=mat[0].size();
        for(int i=x;i<mat.size();i++){
            for(int j=y;j<n;j++){
                if(mat[i][j]) cnt++;
                else n=j;
            }
        }
        return cnt; 
    }
    
    int numSubmat(vector<vector<int>>& mat){
        int res=0;        
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++)
                res+=find(mat,i,j);
        return res;
    }
};