class Solution {
public:
    void solve(vector<int>& candidates, int target, int ind, vector<vector<int>>& ans, vector<int>& tmp){
        if(target == 0){
            ans.push_back(tmp);
            return;
        }
        if(ind == candidates.size() || target < 0) 
            return;
        tmp.push_back(candidates[ind]);
        solve(candidates, target-candidates[ind], ind, ans, tmp);
        tmp.pop_back();
        solve(candidates, target, ind+1, ans, tmp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(candidates, target, 0, ans, tmp);
        return ans;
    }
};