class Solution {
public:
    int isPossible(vector<int>& nums, int k, int m){
        int h = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= m){
                h++;
                i++;
            }
        }
        return h >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end());
        int h = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while(l<=h){
            int m = l + (h-l)/2;
            if(isPossible(nums, k, m)){
                ans = m;
                h=m-1;
            }
            else{
                l = m+1;
            }
        }
        return ans;
    }
};