class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = count(nums.begin(), nums.end(), 1);
        int n =nums.size();
        for(int i=0; i<n; i++){
            nums.push_back(nums[i]);
        }
        int z = count(nums.begin(), nums.begin()+k, 0);
        int ans = z;
        for(int i=k; i<nums.size(); i++){
            if(nums[i-k]==0)
                z--;
            if (nums[i]==0)
                z++;
            ans = min(ans, z);
        }
        return ans;
    }
};