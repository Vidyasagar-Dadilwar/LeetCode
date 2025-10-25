class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = 0, cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(cnt == 0){
                cnt = 1;
                maj = nums[i];
            }
            else if(maj == nums[i])
                cnt++;
            else if(maj != nums[i])
                cnt--;
        }
        cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == maj)
                cnt++;
        }
        if(cnt > nums.size()/2)
            return maj;
        return -1;
    }
};