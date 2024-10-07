class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ms = INT_MIN, s=0;
        for(auto i: nums){
            s+=i;
            ms=max(ms, s);
            if(s<0){
                s=0;
            }
        }
        return ms;
    }
};