class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i+1])
            i--;
        if(i >= 0){
            for(int j=nums.size()-1; j>i; j--){
                if(nums[j]>nums[i]){
                    swap(nums[j], nums[i]);
                    break;
                }
            }
        }
        reverse(nums.begin()+(i+1), nums.end());
    }
};