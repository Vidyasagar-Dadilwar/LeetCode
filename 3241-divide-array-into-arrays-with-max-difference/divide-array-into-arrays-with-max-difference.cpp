class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> result;
        int n = nums.size();        
        if (n%3 != 0) 
            return result;  
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 3) {
            vector<int> t = {nums[i], nums[i + 1], nums[i + 2]};
            if (t[2] - t[0] > k) 
                return {};  
            result.push_back(t);
        }
        return result;
    }
};