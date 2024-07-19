class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> mini(matrix.size());
        vector<int> maxi(matrix[0].size(), INT_MIN);
        
        for(int i = 0; i < matrix.size(); i++) {
            mini[i] = *min_element(matrix[i].begin(), matrix[i].end());
        }
        for(int j = 0; j < matrix[0].size(); j++) {
            for(int i = 0; i < matrix.size(); i++) {
                maxi[j] = max(maxi[j], matrix[i][j]);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == mini[i] && matrix[i][j] == maxi[j]) {
                    ans.push_back(matrix[i][j]);
                    break;
                }
            }
        }   
        return ans;
    }
};