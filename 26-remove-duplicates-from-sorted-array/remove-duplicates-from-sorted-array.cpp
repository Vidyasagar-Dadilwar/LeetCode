class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1, j = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[j]){
                cnt++;
                swap(nums[++j], nums[i]);
            }
        }
        return cnt;
    }
};