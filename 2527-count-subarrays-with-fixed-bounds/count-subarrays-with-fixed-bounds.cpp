class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        int i=0,j=0,cnt=0,l=-1,r=-1,bad_ind=-1;
        long long ans=0;
        while(i<n){
            if(!(minK<=nums[i] && nums[i]<=maxK)){
                bad_ind=i;
            }
            if(nums[i]==minK){
                l=i;
            }
            if(nums[i]==maxK){
                r=i;
            }
            ans+=max(0,min(l,r)-bad_ind);
            i++;
        }
        return ans;
    }
};