class Solution {
public:
    void solve(vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans, int ind, int target) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i = ind; i < candidates.size(); i++) {
            if(i > ind && candidates[i] == candidates[i - 1])
                continue;
            if(candidates[i] > target) 
                break;
            
            temp.push_back(candidates[i]);
            solve(candidates, temp, ans, i + 1, target - candidates[i]);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        solve(candidates, temp, ans, 0, target);
        return ans;
    }
};