class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int l = 0, r = 0, sum = 0, maxi = 0, n = nums.size();

        while(r < n){
            while(st.find(nums[r]) != st.end()){
                st.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
            st.insert(nums[r]);
            sum += nums[r];
            maxi = max(maxi, sum);
            r++;
        }
        return maxi;
    }
};