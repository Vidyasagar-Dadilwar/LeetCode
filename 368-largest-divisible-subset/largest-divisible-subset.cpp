class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>ans;
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        vector<int>facts(n,1);
        vector<int>next(n,-1);
        int maxi=0;
        int maxidx=0;
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0){
                    if(facts[j]+1>facts[i]){
                        facts[i]=facts[j]+1;    
                        next[i]=j;
                    }
                    if(facts[i]>maxi){
                        maxi=facts[i];
                        maxidx=i;
                    }
                }
            }
        }
        int i=maxidx;
        while(i!=-1){
            ans.push_back(nums[i]);
            i=next[i];
        }
        return ans;
    }
};