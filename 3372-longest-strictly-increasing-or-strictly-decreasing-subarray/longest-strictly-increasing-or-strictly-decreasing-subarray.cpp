class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxI = 1, maxD = 1, ans = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] > nums[i]){
                maxD++;
                maxI = 1;
            }
            else if(nums[i-1] < nums[i]){
                maxI++;
                maxD = 1;
            }
            else{
                maxI = maxD = 1;
            }
            ans = max(ans, max(maxI, maxD));
        }
        return ans;
    }
};