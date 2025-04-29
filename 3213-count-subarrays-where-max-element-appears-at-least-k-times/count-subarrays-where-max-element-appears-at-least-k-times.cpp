class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int maxi=*max_element(nums.begin(),nums.end()),i=0,j=0,ans=0,cnt=0,n=nums.size();
        unordered_map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;
            while(i<=j && mp[maxi]>=k){
                ans+=(n-j);
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};