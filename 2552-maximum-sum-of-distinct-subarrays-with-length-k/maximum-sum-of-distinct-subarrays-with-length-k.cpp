class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l=0, r=0;
        long long int sum = 0, maxSum= LLONG_MIN;
        unordered_map<int, int> freq;
        while(r<nums.size()){
            sum+=nums[r];
            freq[nums[r]]++;
            while(r-l+1>k){
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }
                sum -= nums[l];
                l++;
            }
            if(r-l+1==k && freq.size() == k){
                maxSum = max(maxSum, sum);
            }
            r++;
        }
        return maxSum == LLONG_MIN ? 0 : maxSum;
    }
};