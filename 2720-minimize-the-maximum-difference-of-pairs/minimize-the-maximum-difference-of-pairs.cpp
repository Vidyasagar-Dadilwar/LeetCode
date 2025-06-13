class Solution {
public:
    int solve(vector<int> nums, int m){
        int n = nums.size();
        int i = 1, cnt = 0;
        while(i < n){
            if(abs(nums[i-1]-nums[i]) <= m){
                cnt++;
                i += 2;
            }
            else
                i++;
        }
        return cnt;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        if(p == 0)
            return 0;
        int n = nums.size();
        int l = 0, h = nums[n-1] - nums[0];
        while(l <= h){
            int m = l + (h - l)/2;
            if(solve(nums, m) >= p)
                h = m-1;
            else
                l = m+1;
        }
        return l;
    }
};