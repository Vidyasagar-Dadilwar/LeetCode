class Solution {
public:
    int MOD = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1;
        vector<int> arr(r+1, 1);

        for(int i=1; i<=r; i++)
            arr[i] = (arr[i-1]*2)%MOD;
        
        int res = 0;
        while(l <= r){
            if(nums[l] + nums[r] <= target){
                res = (res + arr[r-l])%MOD;
                l++;
            }
            else
                r--;
        }
        return res;
    }
};