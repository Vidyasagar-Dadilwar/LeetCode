class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
    
        for (int i = 0; i < n; ++i) {
            int current_sum = 0;
            for (int j = i; j < n; ++j) {
                current_sum += (nums[j]);
                sums.push_back(current_sum);
            }
        }
        
        sort(sums.begin(), sums.end());
        
        long long result = 0;
        int mod = 1e9 +7;
        for (int i = left - 1; i < right; ++i) {
            result = (result + sums[i])%mod;
        }
        
        return (result);
    }
};