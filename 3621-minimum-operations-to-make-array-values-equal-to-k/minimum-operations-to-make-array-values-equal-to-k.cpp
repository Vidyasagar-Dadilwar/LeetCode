class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(auto i: nums){
            if(i > k)
                st.insert(i);
            else if(i < k)
                return -1;
        }
        return st.size();
    }
};