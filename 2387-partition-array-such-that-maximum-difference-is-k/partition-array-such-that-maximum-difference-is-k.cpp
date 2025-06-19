class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 1;
        int mini = INT_MAX, maxi = INT_MIN, diff = INT_MAX;
        for(int i=0;i <nums.size(); i++){
            mini = min(nums[i], mini);
            maxi = max(nums[i], maxi);
            if(maxi-mini > k){
                cnt++;
                mini = nums[i]; maxi = nums[i];
            }
        }
        return cnt;
    }
};