class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int up = 1, prevUp = 1, res = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1])
                up++;
            else{
                prevUp = up;
                up = 1;
            }
            int half = up/2, mini = min(prevUp, up), cad = max(half, mini);
            if(cad > res)   res = cad;
        }
        return res;
    }
};