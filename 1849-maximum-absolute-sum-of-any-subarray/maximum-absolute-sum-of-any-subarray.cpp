class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = INT_MIN, minSum = INT_MAX, sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            minSum = min(minSum, sum);
            if(sum > 0)
                sum = 0;
        }
        return max(abs(maxSum), abs(minSum));
    }
};