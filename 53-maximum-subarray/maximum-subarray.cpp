class Solution {
public:
    bool allNeg(vector<int> arr){
        for(auto it: arr){
            if(it >= 0)
                return false;
        }
        return true;
    }
    int maxSubArray(vector<int>& nums) {
        int maxi = 0, sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum < 0)
                sum = 0;
            maxi = max(maxi, sum);
        }
        if(allNeg(nums))
            return *max_element(nums.begin(), nums.end());
        return maxi;
    }
};