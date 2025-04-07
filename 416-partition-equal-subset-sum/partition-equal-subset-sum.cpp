class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tsum = accumulate(nums.begin(), nums.end(), 0);
        if(tsum % 2 != 0)
            return false;
        int t = tsum / 2;
        vector<bool> arr(t+1, false);
        arr[0] = true;
        for(auto i: nums){
            for(int j = t; j >= i; j--)
                arr[j] = arr[j] || arr[j-i];
        }
        return arr[t];
    }
};