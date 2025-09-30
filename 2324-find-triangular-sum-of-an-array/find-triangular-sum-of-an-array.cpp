class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int cnt = 0;
        while(cnt < nums.size()){
            for(int i=0; i<nums.size()-cnt-1; i++)
                nums[i] = (nums[i] + nums[i+1]) % 10;
            cnt++;
        }
        return nums[0];
    }
};