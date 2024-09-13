class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>xorr(1, 0), ans;
        for(int i=0; i<arr.size(); i++){
            xorr.push_back(arr[i]^xorr[i]);
        }
        for(auto q: queries){
            ans.push_back(xorr[q[1]+1]^xorr[q[0]]);
        }
        return ans;
    }
};