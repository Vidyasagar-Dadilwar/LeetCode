class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = 0, sum = 0, allNeg = 1;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum < 0)
                sum = 0;
            maxi = max(maxi, sum);
            if(nums[i] >= 0)
                allNeg = 0;
        }
        return allNeg ? *max_element(nums.begin(), nums.end()) : maxi;
    }
};