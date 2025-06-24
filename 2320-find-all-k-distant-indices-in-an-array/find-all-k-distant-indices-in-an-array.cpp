class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(nums[j] == key && abs(i-j) <= k && find(ans.begin(), ans.end(), i) == ans.end())
                    ans.push_back(i);
            }
        }
        return ans;
    }
};