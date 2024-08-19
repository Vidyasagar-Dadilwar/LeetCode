class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        for(int i: nums){
            if(i<k){
                ans++;
            }
        }
        return ans;
    }
};