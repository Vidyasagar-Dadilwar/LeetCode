class Solution {
  public:
    vector<int> getAlternates(vector<int> &arr) {
        // code here
        vector<int> ans;
        for(int ind=0; ind<arr.size(); ind+=2){
            ans.push_back(arr[ind]);
        }
        return ans;
    }
};