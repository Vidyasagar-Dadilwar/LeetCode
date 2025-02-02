class Solution {
public:
    bool check(vector<int>& nums) {
        int i=0;
        int index=-1;
        bool flag=false;
        for(i=0;i<nums.size()-1;i++){
            if(nums[i] > nums[i+1]){
                if(flag==false){
                    flag=true;
                    index = i+1;
                }
                else
                    return false;
            }
        }
        int p = nums[0];
        if(flag){
            for(i=index;i<nums.size();i++){
                    if(nums[i] > p)
                    return false;
                }
        }
        return true;
    }
};