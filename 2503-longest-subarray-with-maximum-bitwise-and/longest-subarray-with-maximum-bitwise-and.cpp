class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int j = -1;
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != maxi){
                j = i;
            }
            ans = max(ans, i-j);
        }
        return ans;
    }
};