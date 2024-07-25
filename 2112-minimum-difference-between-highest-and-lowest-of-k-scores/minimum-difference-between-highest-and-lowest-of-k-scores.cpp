class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minDiff = INT_MAX;

        int l=0, r=k-1;
        int diff=nums[r]-nums[l];
        while(r<n){
            diff=nums[r]-nums[l];
            minDiff=min(minDiff, diff);
            l++; r++;
        }
        return minDiff;
    }
};