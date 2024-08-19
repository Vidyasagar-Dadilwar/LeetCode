class Solution {
public:
    int findFirst(vector<int>nums, int target){
        int l=0, h=nums.size()-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(nums[m]<target){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        if(l<nums.size() && nums[l]==target){
            return l;
        }
        return -1;
    }
    
    int findLast(vector<int>nums, int target){
        int l=0, h=nums.size()-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(nums[m]>target){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        if(h>=0 && nums[h]==target){
            return h;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> ans(2, -1); 
        ans[0]=findFirst(nums, target);
        if(ans[0]!=-1)
            ans[1]=findLast(nums, target);
        return ans;
    }
};