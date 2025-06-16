class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = nums[0], maxi = -1, diff = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] <= mini)
                mini = nums[i];
            else{
                diff = nums[i] - mini;
                maxi = max(maxi, diff);
            }
        }
        return maxi;
    }
};