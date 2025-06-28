class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> arr;
        for(int i=0; i<nums.size(); i++)
            arr.push_back({nums[i], i});
        sort(arr.rbegin(), arr.rend());
        vector<pair<int, int>> ar1;
        for(int i=0; i<k; i++){
            ar1.push_back({arr[i].second, arr[i].first});
        }
        sort(ar1.begin(), ar1.end());
        vector<int> ans;
        for(int i=0; i<ar1.size(); i++)
            ans.push_back(ar1[i].second);
        return ans;
    }
};